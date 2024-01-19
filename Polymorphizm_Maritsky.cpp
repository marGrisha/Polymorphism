#include <iostream>
#include <vector>

class Pizza
{
public:
    virtual ~Pizza() {}

    virtual void printDetails() const = 0;
    virtual int calculatePrice() const = 0;
    virtual void setSize(int size) = 0;
    virtual void addSalt(int amount) = 0;
    virtual void addCheese(int amount) = 0;
};

class Napoletana : public Pizza
{
private:
    std::string name;
    std::string description;
    int size;
    int salt;
    int cheese;

public:
    Napoletana() : name("Неаполитанская пицца"), description("Tоматы San Marzano, натуральный сыр Mozzarella Fior di Latte, ароматние травы"), size(25), salt(0), cheese(0) {}

    void printDetails() const override
    {
        std::cout << "Название: " << name << std::endl;
        std::cout << "Описание: " << description << std::endl;
        std::cout << "Размер: " << size << std::endl;
        std::cout << "Сыр: " << cheese << std::endl;
        std::cout << "Соль: " << salt << std::endl;
        std::cout << "Стоимость: " << calculatePrice() << std::endl;
    }

    int calculatePrice() const override
    {
        return size * 15 + cheese * 6 + salt * 3;
    }

    void setSize(int newSize) override
    {
        size = newSize;
    }

    void addSalt(int amount) override
    {
        salt += amount;
    }

    void addCheese(int amount) override
    {
        cheese += amount;
    }
};

class Margherita : public Pizza
{
private:
    std::string name;
    std::string description;
    int size;
    int salt;
    int cheese;

public:
    Margherita() : name("Маргарита"), description("классическая итальянская пицца с томатами и моцареллой."), size(25), salt(0), cheese(0) {}

    void printDetails() const override
    {
        std::cout << "Название: " << name << std::endl;
        std::cout << "Описание: " << description << std::endl;
        std::cout << "Размер: " << size << std::endl;
        std::cout << "Сыр: " << cheese << std::endl;
        std::cout << "Соль: " << salt << std::endl;
        std::cout << "Стоимость: " << calculatePrice() << std::endl;
    }

    int calculatePrice() const override
    {
        return size * 7 + cheese * 20 + salt * 1;
    }

    void setSize(int newSize) override
    {
        size = newSize;
    }

    void addSalt(int amount) override
    {
        salt += amount;
    }

    void addCheese(int amount) override
    {
        cheese += amount;
    }
};

class Carbonara : public Pizza
{
private:
    std::string name;
    std::string description;
    int size;
    int salt;
    int cheese;

public:
    Carbonara() : name("Карбонара"), description("Пицца состоит из основного теста для пиццы, покрытого томатным соусом и сверху ломтиками бекона, соуса из яиц и сыра."), size(25), salt(0), cheese(0) {}

    void printDetails() const override
    {
        std::cout << "Название: " << name << std::endl;
        std::cout << "Описание: " << description << std::endl;
        std::cout << "Размер: " << size << std::endl;
        std::cout << "Сыр: " << cheese << std::endl;
        std::cout << "Соль: " << salt << std::endl;
        std::cout << "Стоимость: " << calculatePrice() << std::endl;
    }

    int calculatePrice() const override
    {
        return size * 60 + cheese * 13 + salt * 3;
    }

    void setSize(int newSize) override
    {
        size = newSize;
    }

    void addSalt(int amount) override
    {
        salt += amount;
    }

    void addCheese(int amount) override
    {
        cheese += amount;
    }
};

class Marinara : public Pizza
{
private:
    std::string name;
    std::string description;
    int size;
    int salt;
    int cheese;

public:
    Marinara() : name("Маринара"), description("Невероятно вкусная пицца с томатами и сыром."), size(25), salt(0), cheese(0) {}

    void printDetails() const override
    {
        std::cout << "Название: " << name << std::endl;
        std::cout << "Описание: " << description << std::endl;
        std::cout << "Размер: " << size << std::endl;
        std::cout << "Сыр: " << cheese << std::endl;
        std::cout << "Соль: " << salt << std::endl;
        std::cout << "Стоимость: " << calculatePrice() << std::endl;
    }

    int calculatePrice() const override
    {
        return size * 44 + cheese * 14 + salt * 5;
    }

    void setSize(int newSize) override
    {
        size = newSize;
    }

    void addSalt(int amount) override
    {
        salt += amount;
    }

    void addCheese(int amount) override
    {
        cheese += amount;
    }
};

class PizzaOrder
{
private:
    std::vector<Pizza *> pizzas;

public:
    ~PizzaOrder()
    {
        clearOrder();
    }

    void addPizza(Pizza *pizza)
    {
        pizzas.push_back(pizza);
    }

    void printOrder() const
    {
        std::cout << "Ваш заказ:" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        int total = 0;
        for (const auto &pizza : pizzas)
        {
            std::cout << "Позиция" << std::endl;
            pizza->printDetails();
            std::cout << "----------------------------------------" << std::endl;
            total += pizza->calculatePrice();
        }

        std::cout << "Итого: " << total << std::endl;
    }

    void clearOrder()
    {
        for (auto pizza : pizzas)
        {
            delete pizza;
        }
        pizzas.clear();
    }
};

int main()
{
    PizzaOrder order;

    int choice;
    do
    {
        std::cout << "1) Неаполитанская пицца\n2) Маргарита\n3) Карбонара\n4) Маринара\n Введите 1-4, чтобы выбрать пиццу или 0 чтобы закончить: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            Pizza *pizza = nullptr;
            switch (choice)
            {
            case 1:
                pizza = new Napoletana();
                break;
            case 2:
                pizza = new Margherita();
                break;
            case 3:
                pizza = new Carbonara();
                break;
            case 4:
                pizza = new Marinara();
                break;
            }

            if (pizza)
            {
                int sizeChoice;
                std::cout << "1) 25\n2) 30\n3) 35\n4) 40\nEnter 1-4 to choose pizza size: ";
                std::cin >> sizeChoice;
                pizza->setSize(20 + sizeChoice * 5);

                int saltAmount, cheeseAmount;
                std::cout << "Сколько соли (0-10): ";
                std::cin >> saltAmount;
                pizza->addSalt(saltAmount);

                std::cout << "Сколько сыра (0-10): ";
                std::cin >> cheeseAmount;
                pizza->addCheese(cheeseAmount);

                order.addPizza(pizza);
            }
        }
        else if (choice == 0)
        {
            order.printOrder();
            order.clearOrder();
        }
    } while (choice != 0);

    return 0;
}