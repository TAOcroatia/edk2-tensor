# EDK2 UEFI firmware porting attempt for Google Pixel 6 Pro (and other Tensor devices)

This repo is based on Renegade Project (edk2-msm). 
It will contain the old files and the file structure for the time being.

The folder layout and the way the project builds are bound to change a lot.


| ![IMG_20230909_211830](https://github.com/TAOcroatia/edk2-tensor/assets/34100820/fda6cfe4-c227-48e2-acb1-f5ffc232818e)  | ![IMG_20230909_211838](https://github.com/TAOcroatia/edk2-tensor/assets/34100820/c53d72fa-ca90-4c11-b3aa-984fd269efc2) | ![IMG_20230909_211841](https://github.com/TAOcroatia/edk2-tensor/assets/34100820/a8c38a8d-34a5-419c-a4b6-22ccb0019f68)  | ![IMG_20230909_211902](https://github.com/TAOcroatia/edk2-tensor/assets/34100820/cb442744-7e25-413c-b2de-ab99aa6373b1) |
| ------------- | ------------- | ------------- | ------------- |

## Enabling PStore debugging 
Run the following commands:
```
fastboot oem ramdump usb
fastboot oem ramdump compression disable
fastboot oem ramdump encryption disable
fastboot oem ramdump config
```

As you can see, these commands will turn your phone into a security hole, so only run them if you are comfortable with that.

## Building and running
Simply execute ``./raven-build-and-run.sh`` with your phone plugged in and in fastboot. After double clicking the power button and waiting for a minute, hold the volume down to get back into fastboot and to get logs (if you run it with -p)

## Memory map
The memory map located at ``Silicon/Google/Tensor/Library/PlatformMemoryMapLib/PlatformMemoryMapLib.c`` is based off of the ouput of ``cat /proc/iomem`` ([formatted nicely here](https://pastebin.com/XcxrZ3VM)) and almost certainly needs work on it done, along with PcdSystemMemoryBase and Size in tensor.dsc.

## Telegram group chat and contributing to the project
Any and all help i can give or receive should go through this [Telegram group](https://t.me/+qsKNlVPyjSo3NGM0)


## Acknowledgements
- Gustave Monce and his [SurfaceDuoPkg](https://github.com/WOA-Project/SurfaceDuoPkg)
- [DuoWoa Project](https://github.com/WOA-Project)
- [EFIDroid](https://github.com/efidroid)
- [Ben (Bingxing) Wang](https://github.com/imbushuo/)
- [Lumia950XLPkg](https://github.com/WOA-Project/Lumia950XLPkg)
- BigfootACA and his [SimpleInit](https://github.com/BigfootACA/simple-init) and [LinuxSimpleMassStorage](https://github.com/BigfootACA/linux-simple-mass-storage)
- fxsheep and his original edk2-sagit
- All the developers and members of [Renegade Project](https://github.com/edk2-porting/) for offering efforts, equipments, valuable documents and more

## License
All code except drivers in GPLDriver directory are licensed under BSD 2-Clause. GPL Drivers are licensed under GPLv2 license.
