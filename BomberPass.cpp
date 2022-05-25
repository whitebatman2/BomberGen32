#include "BomberPass.h"
#include "bomberArrays.h"
#include "helpers.h"


using namespace Bomber;

BomberPass::BomberPass()
:
level			(0),
score			(0),
bombRadius		(0),
bombCount		(0),
detonator		(false),
speed			(false),
wallpass        (false),
flameproof		(false),
highlight		(false),
pass			("")
{
}


BomberPass::~BomberPass()
{
}


std::string BomberPass::getString()
{
	encode();

	std::string str;
	str.resize(20);

    for (unsigned int i = 0; i < 20; i++)
	{
		if (i % 2)
		{
            str[i] = encodeArrEven[static_cast<int>(pass[i])];
		}
		else
		{
            str[i] = encodeArrOdd[static_cast<int>(pass[i])];
		}
	}

	return str;
}


void BomberPass::setLevel(uint8_t level)
{
	this->level = level;
}


void BomberPass::setScore(uint32_t score)
{
	this->score = score - (score % 100);
}


void BomberPass::setBombRadius(uint8_t length)
{
	if (length > 15)
	{
		length = 15;
	}

    bombRadius = length;
}


void BomberPass::setBombCount(uint8_t count)
{
	if (count > 15)
	{
		count = 15;
	}

	bombCount = count;
}


void BomberPass::setDetonator(bool detonator)
{
	this->detonator = detonator;
}


void BomberPass::setSpeed(bool speed)
{
	this->speed = speed;
}


void BomberPass::setWallpass(bool wallpass)
{
	this->wallpass = wallpass;
}


void BomberPass::setFlameproof(bool flameproof)
{
	this->flameproof = flameproof;
}


void BomberPass::setHighlight(bool highlight)
{
	this->highlight = highlight;
}


void BomberPass::encode()
{
	memset(pass, 0, 20);

	_enc_level();
	_enc_score();
	_enc_bomb_length();
	_enc_bomb_count();
	_enc_detonator();
	_enc_speed();
	_enc_wallpass();
	_enc_flameproof();
	_enc_highlight();
}


void BomberPass::_enc_score()
{
	uint32_t score_reduced = score / 100;
	uint8_t score_100 = score_reduced % 10;
	uint8_t score_1000 = (score_reduced / 10) % 10;
	uint8_t score_10000 = (score_reduced / 100) % 10;
	uint8_t score_100000 = (score_reduced / 1000) % 10;
	uint8_t score_1000000 = (score_reduced / 10000) % 10;
	uint8_t score_10000000 = (score_reduced / 100000) % 10;
	uint8_t score_100000000 = (score_reduced / 1000000) % 10;

	multiAdd(pass, 0, 18, score_100);
	multiAdd(pass, 4, 18, score_100);

	multiAdd(pass, 5, 18, -score_1000);
	multiAdd(pass, 9, 18, -score_1000);
	singleAdd(pass, 19, 4 * -score_1000);

	multiAdd(pass, 15, 18, -score_10000);
	singleAdd(pass, 19, 2 * -score_10000);

	multiAdd(pass, 7, 18, -score_100000);
	multiAdd(pass, 9, 18, -score_100000);
	singleAdd(pass, 19, 4 * -score_100000);

	multiAdd(pass, 11, 13, -score_1000000);
	singleAdd(pass, 19, 2 * -score_1000000);

	singleAdd(pass, 13, -score_10000000);
	singleAdd(pass, 19, 2 * -score_10000000);

	singleAdd(pass, 3, -score_100000000);
	singleAdd(pass, 19, 2 * -score_100000000);
}


void BomberPass::_enc_level()
{
	if (level != 0)
	{
		int low_nibble = level & 0x0F;
		int high_nibble = (level >> 4) & 0x0F;

		multiAdd(pass, 6, 8, 1);
		multiAdd(pass, 2, 18, low_nibble);
		multiAdd(pass, 4, 18, low_nibble);

		if (high_nibble != 0)
		{
			multiAdd(pass, 17, 18, -high_nibble);
		}

		singleAdd(pass, 19, (level / 16 + 1) * -2);
	}
}


void BomberPass::_enc_bomb_length()
{
    multiAdd(pass, 6, 8, bombRadius);
    singleAdd(pass, 19, -2 * bombRadius);
}


void BomberPass::_enc_bomb_count()
{
	multiAdd(pass, 10, 18, bombCount);
	multiAdd(pass, 14, 18, bombCount);
}


void BomberPass::_enc_detonator()
{
    multiAdd(pass, 1, 3, -static_cast<int>(detonator));
    singleAdd(pass, 19, -2 * static_cast<int>(detonator));
}


void BomberPass::_enc_speed()
{
    multiAdd(pass, 12, 18, static_cast<int>(speed));
    multiAdd(pass, 14, 18, static_cast<int>(speed));
}


void BomberPass::_enc_wallpass()
{
	singleAdd(pass, 18, wallpass);
}


void BomberPass::_enc_flameproof()
{
	singleAdd(pass, 8, flameproof);
    singleAdd(pass, 19, -2 * static_cast<int>(flameproof));
}


void BomberPass::_enc_highlight()
{
	multiAdd(pass, 16, 18, highlight);
}


std::ostream& operator<<(std::ostream& os, BomberPass& m)
{
	os << m.getString();
	return os;
}
