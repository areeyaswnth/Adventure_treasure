#pragma once
#include "allheader.h"
enum buttonstate{ IDLE = 0,HOVER,PRESS };

#define BACKSPACE 8
#define ESC 27
#define ENTER 13

namespace gui
{
	class Button
	{
	private:

		short unsigned buttonstate;
		short unsigned id;

		RectangleShape shape;
		Font* font;
		Text text;

		Color textIdleColor;
		Color textHoverColor;
		Color textActiveColor;

		Color idleColor;
		Color hoverColor;
		Color activeColor;

		Color outlineIdleColor;
		Color outlineHoverColor;
		Color outlineActiveColor;

	public:
		Button(float x, float y, float width, float height, Font* font, string text, unsigned char_size,
			Color tic, Color thc, Color tac, Color ic, Color hc, Color ac, Color oic = Color::Transparent, Color ohc = Color::Transparent, Color oac = Color::Transparent,
			short unsigned id = 0);
		~Button();

		const bool isPress() const;
		const string getText() const;
		const short unsigned& getId() const;

		void setText(const string text);
		void setId(const short unsigned id);

		void update(const Vector2i& mousePosWindow);
		void render(RenderTarget& target);
	};

	class Textbox
	{
	private:
		RectangleShape shape;
		Text textbox;
		Font* font;

		ostringstream text;
		bool isSelect = false;
		int limit;

		void backspace();
		void getInput(int charType);

	public:
		Textbox(float x, float y, float height, float width, int lim, int char_size,Font* font, bool sel);
		~Textbox();
		string getText();
		bool isSelected();

		void type(Event ev);
		void clearbox();

		void update(const Vector2i& mousePosWindow);
		void render(RenderTarget& target);
	};
}

