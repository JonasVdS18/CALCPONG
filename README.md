# CALCPONG
A custom version of pong for your TI-84 plus CE calculator.

The calculator on the left is controlled with the 2nd key and the alpha key, the calculator on the right is controlled with the up and down arrow keys.

You can download the newest release in the releases tab (on the right side of this github page).
To install the game on your calculator, you will need to have [TI connect CE](https://education.ti.com/en/products/computer-software/ti-connect-ce-sw) and you also need to install the [CE C 'Standard' Libraries](https://github.com/CE-Programming/libraries/releases/tag/v9.0).

This was my first project ever in c/c++ for the TI-84 plus CE calculator, so the code may not be the best, but i've tried my best to restructure the original source code and add comments so that the code makes more sense :)

You are always free to add new features.

# SCREENSHOTS
![CALCPONG_screenshot](https://github.com/user-attachments/assets/79e6526a-3e1d-4440-a300-fd98c262c5f9)
![CALCPONG_video](https://github.com/user-attachments/assets/a0261b6a-3710-45ad-9967-d3c5e96d2946)

# BUILDING
If you would like to build CALCPONG yourself, be sure you have the latest LLVM [CE C Toolchain](https://github.com/CE-Programming/toolchain/releases/latest) installed.

Simply clone or download the repository from above. 
Don't forget to copy one of the makefiles that belongs to your OS (from the makefiles folder) to the root of the project.
Finally run the following commands to build the project:

    make gfx
    make

# INFO
if you want to know more about developing games for the TI-84 plus CE calculator, I highly recommend to take a look at the [CE C Toolchain](https://github.com/CE-Programming/toolchain) they also have a [documentation](https://ce-programming.github.io/toolchain/). You can also use the [CEmu emulator](https://github.com/CE-Programming/CEmu) to experiment on a virtual calculator, so that if you do something wrong, you won't crash your actual calculator.
