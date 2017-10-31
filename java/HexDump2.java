import java.io.*;
import java.util.*;


/**
 * How to run:
 *   $ javac HexDump2.java
 *   $ java HexDump2 HexDump2.java 0 100 16
 */
public class HexDump2 {


	public static void main(String[] args) {
		byte[] bytes = new ContentFile(args[0]).content().getBytes();
		int start = integer(args[1]);
		bytes = slice(bytes, start, integer(args[2]));
		int perLine = integer(args[3]);
		List<Line> chunks = chunks(start, bytes ,perLine);
		for(Line x : chunks)
			x.writeLn(perLine);
	}


	private static String leftPadded(String s, int num) {while (s.length() < num) s = " " + s; return s; }
	private static int integer(String s) {  return Integer.parseInt(s);  }


	private static List<Line> chunks(int start, byte[] bytes, int perLine) {
		List<Line> result = new ArrayList<Line>();
		while (bytes.length > 0) {
			result.add(new Line(start, slice(bytes, 0, perLine)));
			bytes = slice(bytes, perLine, bytes.length);
			start += perLine;
		}
		return result;
	}


	private static byte[] slice(byte[] bytes, int start, int end) {
		if (end > bytes.length) end = bytes.length;
		if (end - start <= 0) return new byte[0];
		byte[] result = new byte[end - start];
		System.arraycopy(bytes, start, result, 0, end - start);
		return result;
	}


	static class ContentFile {
		File file_;
		public ContentFile(String name) {
			file_ = new File(name);
		}
		public String content() {
			try {
				StringBuffer buf = new StringBuffer();
				BufferedReader in = new BufferedReader(new FileReader(file_));
				for(String s = in.readLine(); s != null; s = in.readLine())
					buf.append(s);
				return buf.toString();
			} catch (Exception e) {
				throw new RuntimeException("couldn't get content", e);
			} 
		}
	}


	static class Line {
		final int start;
		final byte[] bytes;
		public Line(int start, byte[] bytes) {
			this.bytes = bytes;
			this.start = start;
		}
		public void writeLn(int perLine) {
			System.out.println("O: " + leftPadded("" + start, 4) + " " + bytesText(perLine) + ":" + text());
		}
		private String text() {
			String result = "";
			for(int i = 0; i < bytes.length; i++) {
				char c = (char) bytes[i];
				result += Character.isLetterOrDigit(c) || Character.isSpace(c) ? c : '.';
			}
			return result;
		}
		private String bytesText(int perLine) {
			String result = "";
			for(int i = 0; i < bytes.length; i++) {
				result += String.format("%02x ", bytes[i]);
			}
			while (perLine-- > bytes.length) result += "   ";
			return result;
		}
	}
}

