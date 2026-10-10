##
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = gta7litewifi
  PLATFORM_GUID                  = FB32BBD0-EBE4-41E6-B6F7-AC5C8FF9CF19
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/gta7litewifiPkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = RELEASE|DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = gta7litewifiPkg/gta7litewifiPkg.fdf
  USE_CUSTOM_DISPLAY_DRIVER      = 0

  #
  # 0 = MT6768
  # 1 = MT6769T
  #
  SOC_TYPE                       = 1

!include MT6768Pkg/MT6768Pkg.dsc.inc

[PcdsFixedAtBuild]
  #
  # DDR Memory
  #
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x40000000
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorModel|"MediaTek (TM) Helio P22T"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorPartNumber|"MT8768T"
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0x0C100000

  #
  # UEFI Stack
  #
  gArmPlatformTokenSpaceGuid.PcdCPUCoresStackBase|0x40000000
  gArmPlatformTokenSpaceGuid.PcdCPUCorePrimaryStackSize|0x40000

  #
  # SMBIOS
  #
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemManufacturer|"Samsung"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemModel|"Galaxy Tab A7 Lite"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"gta7litewifi"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"SM-T220"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemBoardModel|"Galaxy Tab A7 Lite"

  #
  # Simple Frame Buffer
  #
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferWidth|800
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferHeight|1340
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferColorDepth|32

  #
  # Storage
  #
  gMediaTekPkgTokenSpaceGuid.PcdStorageIsEMMC|TRUE

[LibraryClasses]
  #
  # Memory Libraries
  #
  MemoryMapLib|gta7litewifiPkg/Library/MemoryMapLib/MemoryMapLib.inf

  #
  # Input Libraries
  #
  KeypadDeviceLib|gta7litewifiPkg/Library/KeypadDeviceLib/KeypadDeviceLib.inf

[Components]
  #
  # ACPI Tables
  #
  gta7litewifi/AcpiTables.inf

  #
  # Input
  #
  SiliciumPkg/Drivers/KeypadDxe/KeypadDxe.inf
  SiliciumPkg/Drivers/KeypadDeviceDxe/KeypadDeviceDxe.inf
[BuildOptions]
  *_CLANGPDB_*_CC_FLAGS = -Wno-unused-but-set-variable


[BuildOptions]
  *_CLANGPDB_*_CC_FLAGS = -Wno-unused-but-set-variable

[BuildOptions]
  *_CLANGPDB_*_CC_FLAGS = -Wno-unused-but-set-variable

[BuildOptions]
  *_CLANGPDB_*_CC_FLAGS = -Wno-unused-but-set-variable

[BuildOptions]
  *_CLANGPDB_*_CC_FLAGS = -Wno-unused-but-set-variable

[BuildOptions]
  *_CLANGPDB_*_CC_FLAGS = -Wno-unused-but-set-variable

[BuildOptions]
  *_CLANGPDB_*_CC_FLAGS = -Wno-unused-but-set-variable
