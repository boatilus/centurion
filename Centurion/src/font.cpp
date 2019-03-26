#include "font.h"

using centurion::Font;

Font::Font(const std::string& path, const int size)
{
	font = TTF_OpenFont(path.c_str(), size);
	this->size = size;
}

Font::~Font()
{
	TTF_CloseFont(font);
}

int Font::getSize()
{
	return size;
}

TTF_Font* Font::GetSDLFont()
{
	return font;
}
