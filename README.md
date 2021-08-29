BSoDForever
===========
This software is a computer virus example on 64-bit Windows.

<font color=Red>**WARNING: This software will threaten your computer security and make your computer unusable. Please do not test it on real machine, otherwise all the consequences will be borne by yourself, and the author and copyright owner of this software will not bear any responsibility. For license information, please refer to [LICENSE](https://github.com/szzhouxd/BSoDForever/blob/master/LICENSE).**</font>

As the name suggests, this virus will cause BSoD repeatedly.  
In more detail, when a user tries to log in, the virus will raise a 0xC0000000 ~ 0xCFFFFFFF BSoD randomly.

Recovery
========
To fix an infected machine, follow the steps below:
1. Boot to a PE system or Windows CD
2. Delete the virus executable that you previously ran.
3. Edit the registry:
    * Locate to HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon, change the Userinit entry to the default "C:\Windows\system32\userinit.exe," \(Don't forget the comma\)
	* Locate to HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run, delete the BSoDForever entry.

That's it!

Downloads
=========
This software only supports 64-bit Windows.
Releases can be found here: <https://github.com/szzhouxd/BSoDForever/releases>

Building
========
Run `mingw32-make`. Only MinGW-W64 is supported at present.

License
=======
This software is distributed under The MIT [License](https://github.com/szzhouxd/BSoDForever/blob/master/LICENSE).
