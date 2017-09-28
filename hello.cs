class HelloWorldApp
{
	static void Main()
	{
		System.Console.WriteLine("Hello, world!");
 		System.Windows.Forms.MessageBox.Show("Hello, world!");
	}
}


/**
 * How to run

C:\Windows\Microsoft.NET\Framework\v4.0.30319\csc /optimize /unsafe /t:exe /out:hello.exe /recurse:hello.cs
hello.exe
del hello.exe

 */

