#ifndef BOMBER_PASS
#define BOMBER_PASS

#include <string>
#include <iostream>



class BomberPass
{
public:
	BomberPass();
	~BomberPass();

	std::string getString();
	friend std::ostream& operator<<(std::ostream& os, BomberPass& m);

	void setLevel(uint8_t level);
	void setScore(uint32_t score);
    void setBombRadius(uint8_t length);
	void setBombCount(uint8_t count);
	void setDetonator(bool detonator);
	void setSpeed(bool speed);
	void setWallpass(bool wallpass);
	void setFlameproof(bool flameproof);
	void setHighlight(bool highlight);

private:
	void encode();
	void _enc_score();
	void _enc_level();
	void _enc_bomb_length();
	void _enc_bomb_count();
	void _enc_detonator();
	void _enc_speed();
	void _enc_wallpass();
	void _enc_flameproof();
	void _enc_highlight();

	uint8_t level;
	uint32_t score;
    uint8_t bombRadius;
	uint8_t bombCount;
	bool detonator;
	bool speed;
	bool wallpass;
	bool flameproof;
	bool highlight;

	char pass[20];
};


#endif//BOMBER_PASS
