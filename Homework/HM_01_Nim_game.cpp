#include <std_lib_facilities.h>

int Safety_input() {

    int num;
    bool err = 1;
    while (err) {
        cin >> num;
        if (cin.fail() ) {
            std::cout << "Wrong type, try again, continue typing" << std::endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            err = 0;
        }
    }
    return num;
}

enum game_turn {  
    Computer,
    Player,
    End_game
};

vector<int> Rock_in_range(vector<int> Rocks_num) {
    vector<int> Input (2); //пара чисел на ввод
    Input[0] = Safety_input();
    Input[1] = Safety_input();
    while ( Input[0] <= 0 || Input[0] > int( Rocks_num.size() ) || 
                              Rocks_num[Input[0]-1] < Input[1] ) {
        std::cout << "Incorrect value, please try again, continue typing" << std::endl;
        Input[0] = Safety_input();
        Input[1] = Safety_input();
    }
    return Input;
}

void Interface(vector<int> n_rocks) {  //интерфейс игры
    constexpr int max_len = 15;
    constexpr int s_to_sp_symbol = 3; //len_* + len+space/len_space
    int n_lines = int( n_rocks.size() ); //отображаем кучки камней
    std::cout << "============================================================" << std::endl;
    std::cout << "String's number                                Rock's number" << std::endl;
    for (int i = 0; i < n_lines; ++i) {
        std::cout << " " <<i+1<<"|" << char(9) <<"[";
        for (int k = 0; k < n_rocks[i]; ++k ) {
            std::cout << " " << "* ";
        }
        for (int k = 0; k < s_to_sp_symbol*(max_len - n_rocks[i]); ++k ) {
            std::cout << " ";
        }
        std::cout << " |" << n_rocks[i] << std::endl;
    }
    std::cout << "============================================================" << std::endl;
}

int Nim(vector<int> n_rocks) {  //вычисляем XOR сумму для камешков
    int nim_sum = n_rocks[0];
    int n_lines = int( n_rocks.size() );
    for (int j = 1; j < n_lines; ++j ) {
        nim_sum = nim_sum ^ n_rocks[j];
    };
    return nim_sum;
}

vector<int> Computer_bot(vector<int> n_rocks) {  //Просчитываем наилучший ход
    int n_lines = int( n_rocks.size() );              // для компьютера
    vector<int> n_try_rocks;
    int nim_sum;

    for (int i = 0; i < n_lines; ++i ) {
        for (int k = n_rocks[i]; k > 0; --k ) {
            n_try_rocks = n_rocks;
            n_try_rocks[i] -= k;    
            nim_sum = Nim(n_try_rocks);
            if ( nim_sum == 0 ) {
                return {i, k};     //ищем выигрышную комбинацию
            };                     //если нашли - применяем
        }
    };
    for (int i = 0; i < n_lines; ++i ) {
        if ( n_rocks[i] != 0 ) {
            return {i, 1};       //если не нашли такой - тянем время
        }
    }

}

vector<int> Step(vector<int> line_rocks, vector<int> n_rocks ) {
    n_rocks[ line_rocks[0] ] -= line_rocks[1] ;  //двойка чисел - ход игроков - реализуем его
    return n_rocks;
};

bool End(vector<int> n_rocks) {  //проверка на конец игры
    int line_rocks = int( n_rocks.size() );
    bool Check = 0;
    for (int i = 0; i < line_rocks ; ++i ) {
        Check = Check || ( n_rocks[i] != 0);
    };
    return !Check;   
};

void game_process(game_turn num, vector<int> Rocks_num) {
    vector<int> Steps (2);

    while ( num != End_game) {
        if ( num == Player) {
            std::cout <<     "-------Enter string and rocks(<16) number with enter--------" << std::endl;
            Steps = Rock_in_range(Rocks_num);
            --Steps[0];
            Rocks_num = Step(Steps, Rocks_num);
            std::cout << "\e[1;1H\e[2J";
            std::cout << "Your turn:" << std::endl;
            Interface( Rocks_num );
            if ( End(Rocks_num) ) {  //Конец? Если да - определяем победителя 
                std::cout << "You are winner!" << std::endl; //и выходим из цикла
                num = End_game;
            }
            else {
                num = Computer;
            }

            continue;
        }
        else if ( num == Computer) {
            Steps = Computer_bot(Rocks_num); //записываем в ходы решение компьютера
            Rocks_num = Step(Steps, Rocks_num);
            Interface( Rocks_num );
            std::cout << "Computer's step: " << Steps[0] + 1 << " " << Steps[1] << std::endl;
            if ( End(Rocks_num) ) {    //Конец? Если да - определяем победителя
                std::cout << "You lose:(" << std::endl;  //и выходим из цикла
                num = End_game;
            }
            else {
                num = Player;
            }

            continue;
        }
    }
}

int main() {
    vector<int> Rocks_num;
    int n_lines;
    //vector<int> Input;
    int value; // вспомогательная переменная
    std::cout <<     "-------Enter string and rocks(<16) number with enter--------" << std::endl;
    n_lines = Safety_input();
    while ( n_lines <= 0 ) {
        std::cout << "Incorrect value, please try again, continue typing" << std::endl;
        n_lines = Safety_input();
    }
    game_turn num;
    
    for (int i = 0; (i < n_lines); ++i) {
        value = Safety_input();
        while ( ( value <= 0 || value > 15) ) {
            std::cout << "Incorrect value, please try again, continue typing" << std::endl;
            value = Safety_input();
        };
        Rocks_num.push_back(value);
    }
    std::cout << "Who will start, Computer(1) or Player(2) ?" << std::endl;

    value = Safety_input();
    while ( value != 1 && value != 2) {
        std::cout << "Try again, continue typing" << std::endl;
        value = Safety_input();
    }
    if (value == 1) {
        num = Computer;
    }
    else {
        num = Player;
    }
    Interface(Rocks_num);
    game_process(num, Rocks_num);
}