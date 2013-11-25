Moving something in a circle 2D

int i = 0;

float X = cos(i*0.0174532925);		// 0.0174532925 = 1 radian
float Y = sin(i*0.0174532925);

in loop

	SetSpeedX(X);
	SetSpeedY(Y);
	i++
	
	
	int iCircleCountThingy = 0;
	float X = 0.0f;
	float Y = 0.0f;
	
	if(iCircleCountThingy == 360)
			iCircleCountThingy = 0;

		iCircleCountThingy++;
		X = (float)cos((iCircleCountThingy*0.0174532925));
		Y = (float)sin((iCircleCountThingy*0.0174532925));
		SetSpeedX(X);
		SetSpeedY(Y);