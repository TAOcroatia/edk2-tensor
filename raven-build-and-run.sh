#!/bin/bash

pstore=""
debug="-r DEBUG"

while getopts ":hp" option; do
  case $option in
    h) echo "usage: -p enables pstore, -r switches from DEBUG build to RELEASE"; exit ;;
    p) pstore="--pstore" ;;
    r) debug="" ;;
    ?) echo "error: option -$OPTARG doesn't exist"; exit ;;
  esac
done

rm tools/magiskboot/kernel
rm boot-raven.img
rm -r logs

./build.sh -f -r $debug $pstore -d raven || { echo "Build failed"; exit 1; }
rm boot-raven.img

cp workspace/Build/raven/DEBUG_CLANG38/FV/TENSOR_UEFI.fd-bootshim tools/magiskboot/kernel

cd tools/magiskboot
./magiskboot_x86 repack boot_a
cd ../..
mv tools/magiskboot/new-boot.img boot-raven.img 

fastboot oem ramdump wipe_file kernel.log

fastboot boot boot-raven.img

mkdir logs

echo ""
sec=59
while [ $sec -ge 0 ]; do
	echo -ne "Waiting for watchdog timeout: $sec\033[0K\r"
	let "sec=sec-1"
	sleep 1
done
echo ""
echo "Hold volume down"
echo ""

fastboot oem ramdump stage_mem 0xfd3ff000 0x00100000
fastboot get_staged logs/ramdump1.txt
echo Ramdump1:
cat logs/ramdump1.txt
echo " "

fastboot oem ramdump stage_mem 0xFD4FF000 0x00100000
fastboot get_staged logs/ramdump2.txt
echo Ramdump2:
cat logs/ramdump2.txt
echo " "
