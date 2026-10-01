#import "../YTLitePlus.h"
#import "VersionSpooferLite.h"

static BOOL isVersionSpooferEnabled() {
    return IS_ENABLED(@"enableVersionSpoofer_enabled");
}

%hook YTVersionUtils
+ (NSString *)appVersion {
    if (!isVersionSpooferEnabled()) {
        return %orig;
    }
    return versionSpooferEntries[versionSpooferSelectedIndex()].appVersion;
}
%end
