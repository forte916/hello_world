# -*- coding: utf-8 -*-

# clrをインポートして、System.Windows.Forms.dllを参照に追加
import clr
clr.AddReferenceByPartialName("System.Windows.Forms")

# System.Windows.Forms名前空間からMessageBoxクラスをインポートして
# そのMessageBoxクラスを使ってメッセージ・ボックスを表示
from System.Windows.Forms import MessageBox
MessageBox.Show("Hello IronPython!", "Insider.NET") 

from System import Console
Console.WriteLine(u"あいうえお(Console版)")

'''
How to run

1. Download IronPython-2.7.7-win.zip
1. Extract zip
1. Set full path of extracted(installed) folder into PATH environment variable.
1. Type following command in terminal.
    ipy hello_ironpython.py
'''
