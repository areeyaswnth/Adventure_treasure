#include "Gui.h"

gui::Button::Button(float x, float y, float width, float height, Font* font, string text, unsigned char_size, Color tic, Color thc, Color tac, Color ic, Color hc, Color ac, Color oic, Color ohc, Color oac, short unsigned id)
{
	this->buttonstate = IDLE;
	this->id = id;

	this->shape.setPosition(Vector2f(x,y));
	this->shape.setSize(Vector2f(width,height));
	this->shape.setFillColor(ic);
	this->shape.setOutlineColor(oic);
	this->shape.setOutlineThickness(1.f);

	this->font = font;

	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setCharacterSize(char_size);
	this->text.setFillColor(tic);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y
	);

	this->textActiveColor = tac;
	this->textHoverColor = thc;
	this->textIdleColor = tic;

	this->idleColor = ic;
	this->activeColor = ac;
	this->hoverColor = hc;

	this->outlineIdleColor = oic;
	this->outlineActiveColor = oac;
	this->outlineHoverColor = ohc;
}

gui::Button::~Button()
{
}

const bool gui::Button::isPress() const
{
	if (this->buttonstate == PRESS)
		return true;
	else
		return false;
}

const string gui::Button::getText() const
{
	return this->text.getString();
}

const short unsigned& gui::Button::getId() const
{
	return this->id;
}

void gui::Button::setText(const string text)
{
	this->text.setString(text);
}

void gui::Button::setId(const short unsigned id)
{
	this->id = id;
}

void gui::Button::update(const Vector2i& mousePosWindow)
{
	this->buttonstate = IDLE;

	if (this->shape.getGlobalBounds().contains(static_cast<Vector2f>(mousePosWindow)))
	{
		this->buttonstate = HOVER;

		if (Mouse::isButtonPressed(Mouse::Left))
			this->buttonstate = PRESS;
	}

	switch (this->buttonstate)
	{
	case IDLE:
		this->shape.setFillColor(this->idleColor);
		this->shape.setOutlineColor(this->outlineIdleColor);
		this->text.setFillColor(this->textIdleColor);
		break;
	case HOVER:
		this->shape.setFillColor(this->hoverColor);
		this->shape.setOutlineColor(this->outlineHoverColor);
		this->text.setFillColor(this->textHoverColor);
		break;
	case PRESS:
		this->shape.setFillColor(this->activeColor);
		this->shape.setOutlineColor(this->outlineActiveColor);
		this->text.setFillColor(this->textActiveColor);
		break;
	default:
		this->shape.setFillColor(Color::Yellow);
		this->shape.setOutlineColor(Color::Black);
		this->text.setFillColor(Color::Red);
		break;
	}
}

void gui::Button::render(RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}

void gui::Textbox::backspace()
{
	string t = this->text.str();
	string newt = "";
	for (int i = 0; i < t.length() - 1; i++)
		newt += t[i];
	this->text.str("");
	this->text << newt;
	this->textbox.setString(this->text.str());
}

void gui::Textbox::getInput(int charType)
{
	if (charType != ESC && charType != BACKSPACE && charType != ENTER)
	{
		this->text << static_cast<char>(charType);
	}
	else if (charType == BACKSPACE)
	{
		if (this->text.str().length() > 0)
		{
			this->backspace();
		}
	}
	//cout << "y";
	this->textbox.setString(this->text.str());
}

gui::Textbox::Textbox(float x, float y, float height, float width, int lim, int char_size, Font* font, bool sel)
{
	this->shape.setPosition(Vector2f(x, y));
	this->shape.setSize(Vector2f(height, width));
	this->shape.setFillColor(Color::White);
	this->shape.setOutlineColor(Color::White);
	this->shape.setOutlineThickness(1.f);

	this->font = font;

	this->textbox.setFont(*this->font);
	this->textbox.setCharacterSize(char_size);
	this->textbox.setFillColor(Color::Black);
	this->textbox.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->textbox.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y
	);

	this->isSelect = sel;
	this->limit = lim;
}

gui::Textbox::~Textbox()
{
}


string gui::Textbox::getText()
{
	return this->text.str();
}

bool gui::Textbox::isSelected()
{
	return this->isSelect;
}

void gui::Textbox::type(Event ev)
{
	//cout << "y";
	if (this->isSelect)
	{
		int chType = ev.text.unicode;

		if (chType < 128)
		{
			if (this->text.str().length() <= this->limit)
			{
				this->getInput(chType);
			}
			else if (this->text.str().length() > this->limit && chType == BACKSPACE)
			{
				this->backspace();
			}
		}
	}
}

void gui::Textbox::clearbox()
{
	this->textbox.setString("");
	this->text.str("");
}

void gui::Textbox::update(const Vector2i& mousePosWindow)
{
	if (this->shape.getGlobalBounds().contains(static_cast<Vector2f>(mousePosWindow)))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			this->isSelect = true;
	}
	else
	{
		if (Mouse::isButtonPressed(Mouse::Left))
			this->isSelect = false;
	}

	switch (this->isSelect)
	{
	case true:
		this->shape.setOutlineColor(Color::Blue);
		break;
	case false:
		this->shape.setOutlineColor(Color::White);
		break;
	default:
		this->shape.setOutlineColor(Color::White);
		break;
	}
}

void gui::Textbox::render(RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->textbox);
}
