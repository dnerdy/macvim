/* vi:set ts=8 sts=4 sw=4 ft=objc:
 *
 * VIM - Vi IMproved		by Bram Moolenaar
 *				MacVim GUI port by Bjorn Winckler
 *
 * Do ":help uganda"  in Vim to read copying and usage conditions.
 * Do ":help credits" in Vim to see a list of people who contributed.
 * See README.txt for an overview of the Vim source code.
 */

#import "MacVim.h"
#import "MMVimControllerDelegate.h"


@class MMWindow;
@class MMFullScreenWindow;
@class MMVimController;
@class MMVimView;

@interface MMWindowController : NSWindowController <NSWindowDelegate, MMVimControllerDelegate, NSOpenSavePanelDelegate, NSToolbarDelegate>
{
    MMVimController     *vimController;
    MMVimView           *vimView;
    BOOL                setupDone;
    BOOL                windowPresented;
    BOOL                shouldResizeVimView;
    BOOL                shouldRestoreUserTopLeft;
    BOOL                shouldMaximizeWindow;
    int                 updateToolbarFlag;
    BOOL                keepOnScreen;
    NSString            *windowAutosaveKey;
    BOOL                fullScreenEnabled;
    MMFullScreenWindow  *fullScreenWindow;
    int                 fullScreenOptions;
    BOOL                delayEnterFullScreen;
    NSRect              preFullScreenFrame;
    MMWindow            *decoratedWindow;
    NSString            *lastSetTitle;
    int                 userRows;
    int                 userCols;
    NSPoint             userTopLeft;
    NSPoint             defaultTopLeft;

    NSToolbar           *toolbar;
    NSMutableDictionary *toolbarItemDict;
}

- (id)initWithVimController:(MMVimController *)controller vimView:(MMVimView *)aVimView;
- (MMVimController *)vimController;
- (MMVimView *)vimView;
- (NSString *)windowAutosaveKey;
- (void)setWindowAutosaveKey:(NSString *)key;
- (void)cleanup;
- (void)openWindow;
- (BOOL)presentWindow:(id)unused;
- (void)updateTabsWithData:(NSData *)data;
- (void)selectTabWithIndex:(int)idx;
- (void)setTextDimensionsWithRows:(int)rows columns:(int)cols isLive:(BOOL)live
                     keepOnScreen:(BOOL)onScreen;
- (void)zoomWithRows:(int)rows columns:(int)cols state:(int)state;
- (void)setTitle:(NSString *)title;
- (void)setDocumentFilename:(NSString *)filename;
- (void)setToolbar:(NSToolbar *)toolbar;
- (BOOL)destroyScrollbarWithIdentifier:(int32_t)ident;
- (BOOL)showScrollbarWithIdentifier:(int32_t)ident state:(BOOL)visible;
- (void)setScrollbarPosition:(int)pos length:(int)len identifier:(int32_t)ident;
- (void)setScrollbarThumbValue:(float)val proportion:(float)prop
                    identifier:(int32_t)ident;
- (void)setDefaultColorsBackground:(NSColor *)back foreground:(NSColor *)fore;
- (void)setFont:(NSFont *)font;
- (void)setWideFont:(NSFont *)font;
- (void)showTabBar:(BOOL)on;
- (void)showToolbar:(BOOL)on size:(NSToolbarSizeMode)size mode:(NSToolbarDisplayMode)mode;
- (void)setMouseShape:(int)shape;
- (void)adjustLinespace:(int)linespace;
- (void)liveResizeWillStart;
- (void)liveResizeDidEnd;

- (void)enterFullScreen:(int)fuoptions backgroundColor:(NSColor *)back;
- (void)leaveFullScreen;
- (void)setFullScreenBackgroundColor:(NSColor *)back;
- (void)invFullScreen:(id)sender;

- (void)setBufferModified:(BOOL)mod;
- (void)setTopLeft:(NSPoint)pt;
- (BOOL)getDefaultTopLeft:(NSPoint*)pt;

- (IBAction)addNewTab:(id)sender;
- (IBAction)toggleToolbar:(id)sender;
- (IBAction)performClose:(id)sender;
- (IBAction)findNext:(id)sender;
- (IBAction)findPrevious:(id)sender;
- (IBAction)vimMenuItemAction:(id)sender;
- (IBAction)vimToolbarItemAction:(id)sender;
- (IBAction)fontSizeUp:(id)sender;
- (IBAction)fontSizeDown:(id)sender;
- (IBAction)findAndReplace:(id)sender;
- (IBAction)zoom:(id)sender;

@end
