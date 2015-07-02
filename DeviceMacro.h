//
//  DeviceMacro.h
//  NewWealink
//
//  Created by Ho on 14/11/19.
//  Copyright (c) 2014年 Ho. All rights reserved.
//

#ifndef NewWealink_DeviceMacro_h
#define NewWealink_DeviceMacro_h

//System

#define IOS_6 ([[UIDevice currentDevice].systemVersion floatValue] >= 6.0)&&([[UIDevice currentDevice].systemVersion floatValue] < 7.0)

#define IOS_7 ([[UIDevice currentDevice].systemVersion floatValue] >= 7.0)&&([[UIDevice currentDevice].systemVersion floatValue] < 8.0)

#define IOS_8 ([[UIDevice currentDevice].systemVersion floatValue] >= 8.0)&&([[UIDevice currentDevice].systemVersion floatValue] < 9.0)

#define IOS_9 ([[UIDevice currentDevice].systemVersion floatValue] >= 9.0)&&([[UIDevice currentDevice].systemVersion floatValue] < 10.0)

//Device Screen

#define windowSize  [UIScreen mainScreen].applicationFrame.size

#define windowWidth  [UIScreen mainScreen].applicationFrame.size.width

#define windowHeight ([UIScreen mainScreen].applicationFrame.size.height+20)

#define iPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)


//int to NSString

#define NSStringFromInt(intValue) [NSString stringWithFormat:@"%d",intValue]

//one pixel line

#define SINGLE_LINE_WIDTH           (1 / [UIScreen mainScreen].scale)
#define SINGLE_LINE_ADJUST_OFFSET   ((1 / [UIScreen mainScreen].scale) / 2)

//Current Language

#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//is Retina?

#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

//is iPad?

#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


//status

#define Success 1
#define Fail    0

#define ON      1
#define OFF     0

//iPhone Device

#if TARGET_OS_IPHONE
#endif

//iPhone Simulator

#if TARGET_IPHONE_SIMULATOR
#endif



//useARC or no
#if __has_feature(objc_arc)
//compiling with ARC
#else
// compiling without ARC
#endif

#pragma mark - common functions
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }

//release object

#define SAFE_DELETE(P) if(P) { [P release], P = nil; }

#define SAFE_RELEASE(x) [x release];x=nil


//read local iamge

#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]]

//define UIImage object

#define IMAGE(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]

//difine UIImage object

#define ImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer]]


//Color transition(16>>RBG)

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


//  RGBA color

#define COLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

//  RGB color

#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)

//backGroundColor

#define BACKGROUND_COLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]


//clera color

#define CLEARCOLOR [UIColor clearColor]

#pragma mark - color functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]


//define font

#define FONT(F) [UIFont fontWithName:@"FZHTJW--GB1-0" size:F]



//G－C－D

#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//NSUserDefaults init

#define USER_DEFAULT [NSUserDefaults standardUserDefaults]


//Radian >> degree

#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)



//Singleton

#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)shared##classname \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [[self alloc] init]; \
} \
} \
\
return shared##classname; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
\
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
}



#endif


//DEBUG  Print current line

#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

//Override NSLog,Debug mode print log and current line

#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif


//DEBUG  Debug mode alert log and current line .

#ifdef DEBUG
#   define ULog(fmt, ...)  { UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }
#else
#   define ULog(...)
#endif


#endif
