#import <Foundation/Foundation.h>

// Shared between the VersionSpooferLite hook and its settings picker so the
// version shown in the picker is always the version that gets spoofed.
// Newest first. YouTube's servers show an "Update available / you're using an
// old version" prompt for clients that are too old, so prefer the top entries.
typedef struct {
    NSString *appVersion;
    NSString *title;
} VersionSpooferEntry;

static const VersionSpooferEntry versionSpooferEntries[] = {
    {@"21.39.4", @"v21.39.4 (Latest - Recommended)"},
    {@"21.33.6", @"v21.33.6"},
    {@"20.10.4", @"v20.10.4 (Last stable v20 for YTLite)"},
    {@"19.49.7", @"v19.49.7 (Last v19 - May show update prompt)"},
    {@"19.28.1", @"v19.28.1 (2024 Thin Icons - May show update prompt)"},
    {@"19.26.5", @"v19.26.5 (2020 Thin Icons - May show update prompt)"},
    {@"18.49.3", @"v18.49.3 (Last v18 - May show update prompt)"},
    {@"18.35.4", @"v18.35.4 (Oldest v18 - May show update prompt)"},
};

static const NSUInteger versionSpooferEntryCount = sizeof(versionSpooferEntries) / sizeof(versionSpooferEntries[0]);

// Stores the selected version string (not an index) so reordering the list
// above never silently changes a user's selection.
static NSString *const kVersionSpooferTargetKey = @"versionSpooferTarget";

static NSUInteger versionSpooferSelectedIndex() {
    NSString *selected = [[NSUserDefaults standardUserDefaults] stringForKey:kVersionSpooferTargetKey];
    for (NSUInteger i = 0; i < versionSpooferEntryCount; i++) {
        if ([versionSpooferEntries[i].appVersion isEqualToString:selected]) return i;
    }
    return 0; // Default to the newest version
}
