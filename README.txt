These are the neccessary files to upload code to the Skybot Flight Controller v0.1 from the Arduino IDE.
FOR USE WITH ARDUINO 1.6.4, COMPATIBILITY WITH OTHER VERSIONS NOT GUARANTEED.

To install, just copy-paste everything into your Arduino install directory (e.g. C:\Program Files (x86)\Arduino) except maybe boards.txt and avrdude.conf (see below).
The information in boards.new.txt must be copy-pasted into your actual boards.txt, and the information in avrdude.new.conf must be copy-pasted into your actual avrdude.conf. Alternatively, you can replace those files with the included ones, at the risk of destroying any of your custom configurations.

To burn the bootloader, the board must be ser to Skybot FC v0.1, but to upload code, the board must be set to Skybot FC v0.1 (w/ 1284p). This is due to using someone else's bootloader hex for the 1284P.

TODO:
-Recompile bootloader with correct device ID.
-Write 1-click patcher script to install files.

CREDITS:
-Bootloader is from https://github.com/stevemarple/Calunium
-"Standard" arduino core is from someone else and is probably just an older version of the Arduino core.