#import <Steam/ChatBubbleView.h>
#import <Steam/ChatBubble.h>

%hook ChatBubbleView

//
// Provide access to the ChatBubbleView's textView object
//
%new -(UITextView*) textView
{
	return objc_getAssociatedObject(self, @selector(textView));
}

-(id)initWithFrame:(CGRect)rect
{
	id result = %orig;
	
	//
	// Register the the associated textView
	//
	NSString *message = self.text;
	UITextView *textView = [[UITextView alloc] initWithFrame:rect]; 
	textView.editable = NO;
	textView.scrollEnabled = NO;
	[textView setDataDetectorTypes:UIDataDetectorTypeLink];
	[textView setText:message];
	[self addSubview:textView];
	objc_setAssociatedObject(self, @selector(textView), textView, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

	self.textView.backgroundColor = [UIColor clearColor];
	self.textView.editable = NO;

	[self.textView release];

	return result;
}

-(void)setText:(id)text bubbleSize:(CGSize)size bubbleType:(int)type avatar:(id)image speakerName:(id)name 
{
	%orig;
 	
	//
	// Fix for persistent link information when scrolling
	// 
	[self.textView setDataDetectorTypes:nil];
	[self.textView setText:nil];
	[self.textView setText:self.text];
	[self.textView setDataDetectorTypes:UIDataDetectorTypeLink];

	[self.textView setFont:[UIFont fontWithName:@"ArialMT" size:10]];
}

- (void)drawRect:(CGRect)rect
{
	//
	// Hide the textView if the ChatBubbleView isn't an actual chat message
	//
	switch(self.bubbleType)
	{
		case kBubbleTypeTimestamp:
		case kBubbleTypeTyping:
		case kBubbleTypePswdMsg:
			[self.textView setText:nil];
			%orig;
			return;
	}

	//
	// Draw an empty chat bubble and profile picture
	//
	CGPoint point = CGPointMake(3, 3);

	if (self.bubbleType == kBubbleTypeRighthand)
		point.x = self.bounds.size.width - self.bubbleSize.width - 3;

	[%c(ChatBubble) drawBubbleWithText:nil atPoint:point bubbleSize:self.bubbleSize bubbleType:self.bubbleType highlighted:self.bHighlighted avatar:self.avatarImage];

	//
	// Set the font, font size, and generate the frame for the textView contents
	//
	double fontSize = [%c(ChatBubble) bubbleFontSize];
	[self.textView setFont:[UIFont fontWithName:@"ArialMT" size:fontSize]];

	NSInteger hAdjust = 4;

	CGRect textRect;
	textRect.origin.x = point.x + self.sideMargin + hAdjust;
	textRect.origin.y = 0;
	textRect.size.width = self.bubbleSize.width;
	textRect.size.height = self.bubbleSize.height + self.topMargin;

	if(self.bubbleType == kBubbleTypeRighthand)
	{
		textRect.origin.x = point.x - self.sideMargin + 4 + hAdjust;
	}

	self.textView.frame = textRect;
}

%end
