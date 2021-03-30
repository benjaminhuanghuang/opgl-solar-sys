
## Movement
planet rotation about Y axis
```
model = glm::rotate( model, angle, glm::vec3( 0.0f, 0.1f, 0.0f ) );
```


orbital motion 

find the x and y coordinates from a radius and the angle

The radius is the distance from the sun to the planet and the angle is the product of a constant value with the frame index. 
```
angle = 0.006f * i  * speed;
radius = 90.0f * scale;
x = radius * sin(PI * 2 * angle / 360);
y = radius * cos(PI * 2 * angle / 360);
model = glm::translate( model, glm::vec3( x, 0.0f, y) );
```


## Light
The light model for this project is initiated in the fragment shader.






## Camera
- yaw rotaion about UP  Y
- pitch rotaion about Side X
- roll  rotaion about Forward
```
  FinalRot =(RollMatrix)(PitchMatrix)(YawMatrix)
```