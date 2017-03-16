/*
** LSfml.cpp for Arcade
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Tue Mar 14 10:08:10 2017 gastal_r
** Last update	Thu Mar 16 21:40:56 2017 gastal_r
*/

#include        "LSfml.hpp"

LSfml::LSfml()
{}

LSfml::~LSfml()
{}

void            LSfml::aInit(size_t width, size_t height)
{
  std::cout << "TEST" << '\n';
  _win.create(sf::VideoMode(width, height),"Arcade");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  _win.clear();
  _win.display();
}

void            LSfml::aClose()
{}

void            LSfml::aTile(size_t x, size_t y, arcade::TileType)
{
  sf::RectangleShape rectangle;

  rectangle.setSize(sf::Vector2f(10, 10));
  rectangle.setFillColor(sf::Color::Green);
  rectangle.setPosition(x, y);
  _win.draw(rectangle);
}

void            LSfml::aTile(size_t x, size_t y, void *texture)
{
  sf::Sprite sprite;
  sf::Texture *test = (sf::Texture*) texture;

  sprite.setTexture(*test);
  sprite.scale(sf::Vector2f(1.f, 1.f));
  sprite.setPosition(x, y);
  _win.draw(sprite);
}

void            *LSfml::aGetTexture(const std::string &path)
{
  sf::Texture *texture = new sf::Texture();

  if (!texture->loadFromFile(path))
    throw arcade::Exception("Failed to load ", path);
  return (texture);
}

sf::Color     LSfml::fillColor(arcade::Color color)
{
  sf::Color   n;

  (color == arcade::WHITE ? n = sf::Color::White :
   (color == arcade::BLUE ? n = sf::Color::Blue :
    (color == arcade::RED ? n = sf::Color::Red :
     (color == arcade::GREEN ? n = sf::Color::Green :
      (color == arcade::MAGENTA ? n = sf::Color::Magenta :
       (color == arcade::CYAN ? n = sf::Color::Cyan :
         (color == arcade::YELLOW ? n = sf::Color::Yellow : sf::Color::Black)))))));
  return (n);
}

void          LSfml::aPutText(size_t x, size_t y, const std::string &fontPath,
                              size_t size, arcade::Color color, const std::string &text)
{
  sf::Font font;

  font.loadFromFile(fontPath);
  sf::Text sfText(text, font);
  sfText.setCharacterSize(30);
  sfText.setStyle(sf::Text::Bold);
  sfText.setFillColor(fillColor(color));
  sfText.setPosition(x, y);
  sfText.setCharacterSize(size);
  _win.draw(sfText);
}

void            LSfml::aClear()
{
  _win.clear();
}

void            LSfml::aRefresh()
{
  _win.display();
}

arcade::CommandType   LSfml::aCommand()
{
  _win.pollEvent(_event);

  if (_event.type == sf::Event::KeyPressed)
  {
    switch (_event.key.code)
    {
      case sf::Keyboard::Escape :
        return (arcade::CommandType::ESCAPE);
      case sf::Keyboard::Up :
        return (arcade::CommandType::GO_UP);
      case sf::Keyboard::Down :
        return (arcade::CommandType::GO_DOWN);
      case sf::Keyboard::Left :
        return (arcade::CommandType::GO_LEFT);
      case sf::Keyboard::Right :
        return (arcade::CommandType::GO_RIGHT);
      case sf::Keyboard::Return :
        return (arcade::CommandType::PLAY);
      default :
        return (arcade::CommandType::UNDEFINED);
    }
  }
  return (arcade::CommandType::UNDEFINED);
}

std::string       LSfml::aChar()
{
  _win.pollEvent(_event);

  if (_event.type == sf::Event::KeyPressed)
  {
    switch (_event.key.code)
    {
      case sf::Keyboard::A :
        return ("A");
      case sf::Keyboard::B :
        return ("B");
      case sf::Keyboard::C :
        return ("C");
      case sf::Keyboard::D :
        return ("D");
      case sf::Keyboard::E :
        return ("E");
      case sf::Keyboard::F :
        return ("F");
      case sf::Keyboard::G :
        return ("G");
      case sf::Keyboard::H :
        return ("H");
      case sf::Keyboard::I :
        return ("I");
      case sf::Keyboard::J :
        return ("J");
      case sf::Keyboard::K :
        return ("K");
      case sf::Keyboard::L :
        return ("L");
      case sf::Keyboard::M :
        return ("M");
      case sf::Keyboard::N :
        return ("N");
      case sf::Keyboard::O :
        return ("O");
      case sf::Keyboard::P :
        return ("P");
      case sf::Keyboard::Q :
        return ("Q");
      case sf::Keyboard::R :
        return ("R");
      case sf::Keyboard::S :
        return ("S");
      case sf::Keyboard::T :
        return ("T");
      case sf::Keyboard::U :
        return ("U");
      case sf::Keyboard::V :
        return ("V");
      case sf::Keyboard::W :
        return ("W");
      case sf::Keyboard::X :
        return ("X");
      case sf::Keyboard::Y :
        return ("Y");
      case sf::Keyboard::Z :
        return ("Z");
      case sf::Keyboard::BackSpace :
        return ("BACKSPACE");
      case sf::Keyboard::Return :
        return ("ENTER");
      case sf::Keyboard::Escape :
        return ("ESCAPE");
      default :
        return ("");
    }
  }
  return ("");
}

extern "C"
{
  LSfml        *createGraph()
  {
    std::cout << "GRAPH" << '\n';
    return (new LSfml());
  }

  void            deleteGame(arcade::IGraph *graph)
  {
    delete(graph);
  }
}