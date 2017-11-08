import java.io.*;
import java.util.*;
import java.nio.charset.Charset;

/**
 * How to run:
 *   $ javac Test.java
 *   $ java Test
 */
public class Test {

	public static void main(String[] args) {
		showEnvironmentVariable();
	}

	/**
	 * Tips: To set default encoding at a launch time, pass a proper value via command line argument.
	 * eg) $ java -Dfile.encoding=UTF-8 Test
	 */
	private static void showEnvironmentVariable() {
		System.out.println(String.format("file.encoding: %s", System.getProperty("file.encoding")));
		System.out.println(String.format("defaultCharset: %s", Charset.defaultCharset().name()));
	}
}

