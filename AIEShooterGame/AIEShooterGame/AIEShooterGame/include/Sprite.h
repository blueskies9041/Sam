
class Sprite : public Vector2D
{
	public:
		Sprite(){};
		Sprite(Vector2D _pos, Vector2D _speed, int _width, int _height, int _spriteID) : position(_pos), speed(_speed), width(_width), height(_height), spriteID(_spriteID) {}
		~Sprite();
	private:
		Vector2D position();
		Vector2D speed();
		int width;
		int height;
		int spriteID;
}