/*===================================================================
 * class_example
 * 
 * This sketch shows the basics of creating and using a simple
 * C++ class.  We create a "car" class that has the ability to
 * do turns, speed up, and slow down.
 */

/* dir_type:  used by the car class to show which direction we're going. */
typedef enum
{
  DIR_NORTH,
  DIR_EAST,
  DIR_SOUTH,
  DIR_WEST
} dir_type;

char *dir_string_table[] =
{
  "North", // DIR_NORTH
  "East",  // DIR_EAST
  "South", // DIR_SOUTH
  "West"   // DIR_WEST
};

char *getDirString(dir_type dir)
{
  return(dir_string_table[dir]);
}

/*==========================================
 * Class:  Car
 * 
 * A car has two intrinsic attributes:
 *   - direction
 *   - speed
 *   
 * Construtors:
 *   A car can either be instantiated with: 
 *     direction specified (speed will be zero)
 *     default (no parameters, speed zero, direction DIR_NORTH.
 *     
 * Public Methods:
 *   Since direction can only be north, south, east, or west, turning left or right turns 
 *   90 degrees to the new direction.
 *   
 *   We can also speed up or slow down.  
 *   On speed up, the car will increase speed by 5 until it hits it's max.  
 *   On slow down, the car will decrease it's speed by 5 until it hits zero.
 *   There is no provision for negative speed (eg, going backwards)
 *   
 *   We also provide access methods for getting current direction and speed.
 ============================================*/
class Car
{
  public:
    Car( void );
    Car( dir_type );
    void turnLeft( void );
    void turnRight( void );
    void speedUp( void );
    void slowDown( void );
    int getSpeed( void );
    dir_type getDir( void );

  private:
    dir_type _currentDir;
    int      _currentSpeed;
    int      _maxSpeed;
};

/*==========================================
 * Default Constructor
 * 
 * Sets default values for direction, speed, and max speed.
 ==========================================*/
Car::Car( void )
{
  _currentDir = DIR_NORTH;
  _currentSpeed = 0;
  _maxSpeed = 65;
}

/*=========================================
 * Car::Car (dir_type)
 * 
 * This constructor creates a car object pointed in the specified direciton.
 ==========================================*/
Car::Car( dir_type init_direction )
{
  _currentDir = init_direction;
  _currentSpeed = 0;
  _maxSpeed = 65;
}

/*==========================================
 * Public Method:  Car::turnLeft
 * 
 * This method sets a car's internal direction to 90 degrees 
 * left of which direction it was previously going.
 ============================================*/
void Car::turnLeft( void )
{
  switch (_currentDir )
  {
    case DIR_NORTH:
      _currentDir = DIR_WEST;
    break;

    case DIR_EAST:
      _currentDir = DIR_NORTH;
    break;

    case DIR_SOUTH:
      _currentDir = DIR_EAST;
    break;

    case DIR_WEST:
      _currentDir = DIR_SOUTH;
    break;

    default:
      Serial.print("Unknown direction in CAR: ");
      Serial.println(_currentDir);
  }
  
  Serial.print("Turned Left.  New dir = ");
  Serial.println(_currentDir);
}

/*==========================================
 * Public Method:  Car::turnRight
 * 
 * This method sets a car's internal direction to 90 degrees 
 * right of which direction it was previously going.
 ============================================*/
void Car::turnRight( void )
{
  switch (_currentDir )
  {
    case DIR_NORTH:
      _currentDir = DIR_EAST;
    break;

    case DIR_EAST:
      _currentDir = DIR_SOUTH;
    break;

    case DIR_SOUTH:
      _currentDir = DIR_WEST;
    break;

    case DIR_WEST:
      _currentDir = DIR_NORTH;
    break;

    default:
      Serial.print("Unknown direction in CAR: ");
      Serial.println(_currentDir);
  }

  Serial.print("Turned Right.  New dir = ");
  Serial.println(_currentDir);
}

/*==========================================
 * Public Method:  Car::speedUp
 * 
 * This method increases the car's internal speed by 5 until it reaches
 *  a cap.
 ============================================*/
void Car::speedUp( void )
{
  Serial.print("Speeding up --> ");

  _currentSpeed = _currentSpeed + 5;
  if (_currentSpeed >= _maxSpeed) 
  {
    _currentSpeed = _maxSpeed;
    Serial.print("Hit max speed:  ");
    Serial.println(_currentSpeed);
  }
  else
  {
    Serial.print("New Speed = ");
    Serial.println(_currentSpeed);
  }
  
}


/*==========================================
 * Public Method:  Car::slowDown
 * 
 * This method decreases the car's internal speed by 5.  
 * We only go down to zero.
 ============================================*/
void Car::slowDown( void )
{
  Serial.print("Slowing down --> ");

  _currentSpeed = _currentSpeed - 5;
  if (_currentSpeed <= 0) 
  {
    _currentSpeed = 0;
    Serial.println("Stopped.");
  }
  else
  {
    _currentSpeed = _currentSpeed - 5;
    Serial.print("New Speed = ");
    Serial.println(_currentSpeed);
  }
}

/*===========================================
 * Public Method:  Car::getSpeed
 * 
 * This method returns the current speed
 ===========================================*/
int Car::getSpeed( void )
{
  return(_currentSpeed);
}

/*==============================================
 * Public Method:  Car::getDirection
 * 
 * This method returns the current direction
 ===============================================*/
dir_type Car::getDir( void )
{
  return(_currentDir);
}



void setup() 
{
  Car tesla;
  Car toyota(DIR_EAST);
  Car *audi;

  audi = new Car(DIR_SOUTH);

  tesla.speedUp();
  toyota.turnRight();
  audi->speedUp();
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
