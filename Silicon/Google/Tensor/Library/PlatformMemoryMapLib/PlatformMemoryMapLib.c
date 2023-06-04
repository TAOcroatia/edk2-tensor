#include <Library/BaseLib.h>
#include <Library/PlatformMemoryMapLib.h>

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Name               Address     Length      HobOption        ResourceAttribute    ArmAttributes
                                                          ResourceType          MemoryType */
    
    {"PStore",        0xfd3ff000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN},
    {"NotPStore",        0xFD4FF000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN},

    
    {"UEFI FD",           0xfa800000, 0x02000000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"CPU Vectors",       0xfd902000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"UEFI Stack",        0x90600000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"DXE Heap",          0x97400000, 0x1fe00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN},
    
    {"Display Reserved",  0xfd90c000, 0x1123000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN},//incorrect framebuffer address
    
    {"RAM Partition",     0x8AF000000, 0x0FDFA0000, Mem4G,  SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    
    {"APSS_GIC500_GICD",  0x10400000, 0x00010000,  AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
    {"APSS_GIC500_GICR",  0x10440000, 0x00100000,  AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},


    /* Terminator for MMU */
    {"Terminator", 0, 0, 0, 0, 0, 0, 0}};

ARM_MEMORY_REGION_DESCRIPTOR_EX *GetPlatformMemoryMap()
{
  return gDeviceMemoryDescriptorEx;
}
