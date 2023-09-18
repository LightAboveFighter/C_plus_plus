#include <std_lib_facilities.h>

void Interface(vector<int> n_rocks) {
    int n_lines = int( n_rocks.size() );
    for (int i = 0; i < 4; ++i) {
        std::cout << std::endl;
    }
    std::cout << "============================================================" << std::endl;
    std::cout << "String's number                                Rock's number" << std::endl;
    for (int i = 0; i < n_lines; ++i) {
        std::cout << " " <<i+1<<"|  [";
        for (int k = 0; k < n_rocks[i]; ++k ) {
            std::cout << " " << "* ";
        }
        for (int k = 0; k < 3*(15 - n_rocks[i]); ++k ) {
            std::cout << " ";
        }
        std::cout << " |" << n_rocks[i] << std::endl;
    }
    std::cout << "============================================================" << std::endl;
    //std::cout << "-------Enter string and rocks(<16) number with space--------" << std::endl;
}

vector<int> Opponent(vector<int> n_rocks) {
    int n_lines = int( n_rocks.size() );
    vector<int> n_try_rocks = n_rocks;
    int nim_sum = n_rocks[ int(n_rocks.size() - 1)];

    for (int i = 0; i < n_lines; ++i ) {
        for (int k = 1; k < n_rocks[i]+1; ++k ) {

            n_try_rocks[i] = k;
            if ( i == int( n_rocks.size() ) ) {
                nim_sum = k;
            };
            for (int j = 0; j < n_lines-1; ++j ) {
                nim_sum = nim_sum ^ n_try_rocks[i];
            };
            if (nim_sum == 0) {
                return {i, n_rocks[i] - k};
            };
        }
    }
}

vector<int> Step(vector<int> line_rocks, vector<int> n_rocks ) {
    n_rocks[ line_rocks[0] ] -= line_rocks[1] ;
    return n_rocks;
};

bool End(vector<int> n_rocks) {
    bool Check = 0;
    for (int i = 0; i < int ( n_rocks.size() ); ++i ) {
        Check = Check || ( n_rocks[i] != 0);
    };
    return !Check;
};

int main() {
    vector<int> Rocks_num;
    int n_lines;
    std::cout <<     "-------Enter string and rocks(<16) number with space--------" << std::endl;
    cin >> n_lines;
    int num;

    for (int i = 0; (i < n_lines); ++i) {
        cin >> num;
        Rocks_num.push_back(num);
    }
    std::cout << "Who will start? Enter 1 - you, 2 - Opponent" << std::endl;
    cin >> num;
    while ( num != 1 && num != 2) {
        std::cout << "Try again" << std::endl;
        cin >> num;
    }
    Interface(Rocks_num);

    vector<int> Steps (2);
    while ( num != -1) {
        if ( num == 1) {
            std::cout <<     "-------Enter string and rocks(<16) number with space--------" << std::endl;
            cin >> Steps[0] >> Steps[1];
            --Steps[0];
            Rocks_num = Step(Steps, Rocks_num);
            std::cout << "Your turn:" << std::endl;
            Interface( Rocks_num );
            if ( End(Rocks_num) ) {
                std::cout << "You are winner!" << std::endl;
                num = -1;
            }
            else {
                num = 2;
            }

            continue;
        }
        else if ( num == 2) {
            Steps = Opponent(Rocks_num);
            Rocks_num = Step(Steps, Rocks_num);
            Interface( Rocks_num );
            std::cout << "Opponent's step: " << Steps[0] + 1 << " " << Steps[1] << std::endl;
            if ( End(Rocks_num) ) {
                std::cout << "You lose:(" << std::endl;
                num = -1;
            }
            else {
                num = 1;
            }

            continue;
        }
        
    }
}