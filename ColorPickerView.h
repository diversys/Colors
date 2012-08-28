/*
 * Copyright 2009-2012 Haiku, Inc. All Rights Reserved.
 * Copyright 2001-2008 Werner Freytag.
 * Distributed under the terms of the MIT License.
 */
#ifndef COLORPICKER_VIEW_H
#define COLORPICKER_VIEW_H


#include <View.h>

#include "color_mode.h"

#define	MSG_RADIOBUTTON		'Rad0'
#define	MSG_TEXTCONTROL		'Txt0'
#define MSG_HEXTEXTCONTROL	'HTxt'


class ColorField;
class ColorSlider;
class ColorPreview;
class EyeDropper;

class BRadioButton;
class BTextControl;

class ColorPickerView : public BView {
	public:
									ColorPickerView();
		virtual						~ColorPickerView();
			
		virtual	void				AttachedToWindow();

		virtual	void				Draw(BRect updateRect);
		virtual	void				MessageReceived(BMessage* message);

		virtual	void				MouseDown(BPoint where);
		virtual	void				MouseMoved(BPoint where, uint32 code,
										const BMessage* message);
		virtual	void				MouseUp(BPoint where);
		virtual	void				Pulse();

				rgb_color			Color();
				color_mode			Mode() const { return fColorMode; }
				void				SaveSettings();
				void				SetColorMode(color_mode mode);
				void				SetColor(rgb_color color);

	private:
				void				_GrabColor();
				void				_UpdateColor(float value, float value1,
												 float value2);
				void				_UpdateTextControls();
				void				_SetText(BTextControl* control,
											 const char* text,
											 bool* requiresUpdate);

				color_mode			fColorMode;

				float				fHue;
				float				fSat;
				float				fVal;

				float				fRed;
				float				fGreen;
				float				fBlue;

				float*				fPointer0;
				float*				fPointer1;
				float*				fPointer2;

				bool				fMouseDown;
				BPoint				fMouseOffset;

				bool				fRequiresUpdate;

				ColorField*			fColorField;
				ColorSlider*		fColorSlider;
				ColorPreview*		fColorPreview;
				EyeDropper*			fEyeDropper;

				BRadioButton*		fRadioButton[6];
				BTextControl*		fTextControl[6];
				BTextControl*		fHexTextControl;
};

#endif	// COLORPICKER_VIEW_H
