# tushtushOS
I follow the little OS book tutorial - [here](https://littleosbook.github.io).
It's not exactly a tutorial as most of the time it sends you searching for answers in the [OSDevWiki](https://wiki.osdev.org) and around the web.
Also it's sometimes missing or has some examples that won't work exactly as they're written on the site so be aware and READ A LOT!

## Running the code
### Dependencies
Works on Ubuntu.
Install dependencies from here:
[Little OS book](https://littleosbook.github.io/#quick-setup)

### Run 
```bash
make run
```
This will start up bochs emulator. On first run, for me it pauses the run and I have to switch back to terminal and run the continue command (either `c` or `continue` in the bochs prompt). I can probably change it in the options but I don't care enough.
### Clean
Use
```bash
make clean
```
To clean the build output.

## Links I used:
* [GDT tutorial on OSDevWiki](https://wiki.osdev.org/GDT_Tutorial)
* [Intel architecture book](https://software.intel.com/sites/default/files/managed/a4/60/325384-sdm-vol-3abcd.pdf) - Look here for the 3-8 diagram that explains the GDT entry.
* [Took this GDT entry structure](https://forum.osdev.org/viewtopic.php?p=178894#p178894)
* [The person I stole the GDT entry from follows this tutorial:](http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html)

## Useful Bochs stuff
* `info gdt` to print out the gdt

## Notes
This repository is my own personal project so there are some weird things here, e.g. log files etc. the more I work on this the more I'll clean it up.
