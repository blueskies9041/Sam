class Vector2D
{
	public:
		Vector2D(): x(0.0f), y(0.0f){}
		Vector2D(float _X, float _Y) : x(_X), y(_Y){}
		~Vector2D(){};

		float GetX() { return x; }
		float GetY() { return y; }
		
		void SetX(float setX) { x = setX; }
		void SetY(float setY) { y = setY; }

	private:
		float x;
		float y;
};