import os
import sys

from edk2toolext.environment.uefi_build import UefiBuilder
from edk2toolext.invocables.edk2_platform_build import BuildSettingsManager
from edk2toolext.invocables.edk2_setup import SetupSettingsManager
from edk2toolext.invocables.edk2_update import UpdateSettingsManager

class PlatformSettingsManager(BuildSettingsManager, SetupSettingsManager, UpdateSettingsManager):
    def init(self):
        self.ActualActiveScopes = []

    def GetConfigFileCurrentUser(self):
        return None

    def GetWorkspaceRoot(self):
        return os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(file))))

    def GetActiveScopes(self):
        return self.ActualActiveScopes

    def GetPlatformDsc(self):
        return os.path.join("Platforms", "Samsung", "gta7litewifiPkg", "PlatformPkg.dsc")

    def GetName(self):
        return "gta7litewifiPkg"

    def GetPackagesPath(self):
        return []

    def GetRequiredSubmodules(self):
        return []

GetSettingsManager = PlatformSettingsManager
