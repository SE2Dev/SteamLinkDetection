#import <UIKit/UIView.h>
//#import <UIKit/UIGestureRecognizerDelegate.h>

@class NSString, UIImage, CustomResponderTextField;

@interface ChatBubbleView : UIView <UIGestureRecognizerDelegate>
{
	NSString* _text;
	NSString* _speakerName;
	CGSize _bubbleSize;
	int _bubbleType;
	BOOL _bHighlighted;
	UIImage* _avatarImage;
	CustomResponderTextField* _inputField;
	double _sideMargin;
	double _topMargin;
}

@property (assign,nonatomic) CGSize bubbleSize;                                  //@synthesize bubbleSize=_bubbleSize - In the implementation block
@property (assign,nonatomic) int bubbleType;                                     //@synthesize bubbleType=_bubbleType - In the implementation block
@property (assign,nonatomic) BOOL bHighlighted;                                  //@synthesize bHighlighted=_bHighlighted - In the implementation block
@property (nonatomic,retain) CustomResponderTextField * inputField;              //@synthesize inputField=_inputField - In the implementation block
@property (nonatomic,retain) NSString * text;                                    //@synthesize text=_text - In the implementation block
@property (nonatomic,retain) NSString * speakerName;                             //@synthesize speakerName=_speakerName - In the implementation block
@property (nonatomic,retain) UIImage * avatarImage;                              //@synthesize avatarImage=_avatarImage - In the implementation block
@property (assign,nonatomic) double sideMargin;                                  //@synthesize sideMargin=_sideMargin - In the implementation block
@property (assign,nonatomic) double topMargin;                                   //@synthesize topMargin=_topMargin - In the implementation block
@property (readonly) NSUInteger hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 

-(void)setAvatarImage:(UIImage *)image ;
-(CGSize)bubbleSize;
-(void)setText:(id)arg1 bubbleSize:(CGSize)size bubbleType:(int)type avatar:(id)image speakerName:(id)name ;
-(void)setInputField:(CustomResponderTextField *)arg1 ;
-(void)setBubbleSize:(CGSize)size ;
-(void)setSideMargin:(double)margin ;
-(UIImage *)avatarImage;
-(BOOL)bHighlighted;
-(void)setSpeakerName:(NSString *)name ;
-(double)sideMargin;
-(CustomResponderTextField *)inputField;
-(void)setBHighlighted:(BOOL)arg1 ;
-(void)hideEditMenu:(id)arg1 ;
-(void)menuControllerDismissed;
-(NSString *)speakerName;
-(double)topMargin;
-(void)setTopMargin:(double)arg1 ;
-(id)initWithFrame:(CGRect)rect ;
-(void)drawRect:(CGRect)rect ;
-(BOOL)canPerformAction:(SEL)arg1 withSender:(id)arg2 ;
-(NSString *)text;
-(void)setText:(NSString *)text ;
-(BOOL)canBecomeFirstResponder;
-(id)accessibilityLabel;
-(void)longPress:(id)arg1 ;
-(void)copy:(id)arg1 ;
-(BOOL)isAccessibilityElement;
-(int)bubbleType;
-(void)setBubbleType:(int)type ;

-(UITextView*) textView;

@end


typedef enum
{
	kBubbleTypeLefthand = 0,
	kBubbleTypeRighthand = 1,
	kBubbleTypeTimestamp = 2,
	kBubbleTypeTyping = 3,
	kBubbleTypePswdMsg = 4,	
}
BubbleType;
