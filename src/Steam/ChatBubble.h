#import <UIKit/UIView.h>
#import <Steam/ChatBubbleView.h>

@interface ChatBubble : NSObject
	+(void)loadResources;
	+(CGSize)getBubbleSizeForText:(id)text bubbleType:(int)type ;
	+(double)getChatRowHeightForText:(id)text bubbleType:(int)type ;
	+(double)warningFontSize;
	+(double)dateFontSize;
	+(double)bubbleFontSize;
	+(id)fontForBubbleType:(int)type ;
	+(double)chatBubbleWrapWidth;
	+(double)chatBubbleTopMargin;
	+(double)chatBubbleBottomMargin;
	+(double)chatBubbleMinWidth;
	+(double)chatBubbleMinHeight;
	+(double)avatarDimension;
	+(double)avatarCornerRadius;
	+(double)chatBubbleTweak;
	+(void)drawTypingBubbleAtPoint:(CGPoint)arg1 bubbleSize:(CGSize)arg2 withAvatar:(id)arg3 ;
	+(void)drawBubbleWithText:(id)arg1 atPoint:(CGPoint)arg2 bubbleSize:(CGSize)arg3 bubbleType:(int)arg4 highlighted:(BOOL)arg5 avatar:(id)arg6 ;
@end