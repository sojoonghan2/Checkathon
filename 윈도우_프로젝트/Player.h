#pragma once
class CPlayer {
private:
	int p_xPos;
	int p_yPos;
	int p_speed;

public:
	CPlayer() {
		p_xPos = 100;
		p_yPos = 100;
		p_speed = 10;
	}
	~CPlayer() {}
	void SetPos(int xPos, int yPos);
	void Move(int xPos);

	int getSpeed() const;
};

