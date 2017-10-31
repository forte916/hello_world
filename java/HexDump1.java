import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.UnsupportedEncodingException;


/**
 * How to run:
 *   $ javac HexDump.java
 *   $ java HexDump HexDump.java 0 100 16
 */
public class HexDump {


	public static void main(String[] args) throws IOException {
		String inputFileName = args[0];
		int start = Integer.parseInt(args[1]);
		int end = Integer.parseInt(args[2]);
		int width = Integer.parseInt(args[3]);
		byte[] bytes = read(inputFileName, start, end);
		for (int index = 0; index < bytes.length; index += width) {
			printHex(bytes, index, width);
			printAscii(bytes, index, width);
		}
	}


	private static byte[] read(String inputFileName, int start, int end)
		throws FileNotFoundException, IOException {
		File theFile = new File(inputFileName);
		FileInputStream input = new FileInputStream(theFile);
		int skipped = 0;
		while (skipped < start) {
			skipped += input.skip(start - skipped);
		}
		int length = (int) (Math.min(end, theFile.length()) - start);
		byte[] bytes = new byte[length];
		int bytesRead = 0;
		while (bytesRead < bytes.length) {
			bytesRead = input.read(bytes, bytesRead, bytes.length - bytesRead);
			if (bytesRead == -1) {
				break;
			}
		}
		return bytes;
	}


	private static void printHex(byte[] bytes, int offset, int width) {
		for (int index = 0; index < width; index++) {
			if (index + offset < bytes.length) {
				System.out.printf("%02x ", bytes[index + offset]);
			} else {
				System.out.print("   ");
			}
		}
	}


	private static void printAscii(byte[] bytes, int index, int width)
		throws UnsupportedEncodingException {
		if (index < bytes.length) {
			width = Math.min(width, bytes.length - index);
			System.out.println(
					":"
					+ new String(bytes, index, width, "UTF-8").replaceAll("\r\n", " ").replaceAll(
						"\n",
						" "));
		} else {
			System.out.println();
		}
	}

}

