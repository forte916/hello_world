import java.io.FileInputStream;

public class HexDump3 {

	public static void main(final String[] args) throws Exception {
		final int width = 3 * Integer.parseInt(args[3]);
		final FileInputStream inS = new FileInputStream(args[0]);
		inS.skip(Integer.parseInt(args[1]));
		final StringBuilder hex = new StringBuilder();
		final StringBuilder chr = new StringBuilder();


		for (int pos = Integer.parseInt(args[2]); pos > 0 && inS.available() > 0; pos--) {
			chr.append((char) inS.read());
			hex.append(String.format("%1$02x ", (byte) chr.charAt(chr.length() - 1)));
			if (hex.length() >= width || pos <= 1) {
				System.out.println(String.format("%1$-" + (width) + "s", hex) + ":" 
						+ chr.toString().replaceAll("[^!-~]", " "));
				hex.setLength(0);
				chr.setLength(0);
			}
		}
	}

}

