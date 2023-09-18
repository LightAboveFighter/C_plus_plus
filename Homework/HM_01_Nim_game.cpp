#include <std_lib_facilities.h>

void Interface(vector<unsigned int> n_rocks) {
    unsigned int n_lines = int( n_rocks.size() );
    //std::cout << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "String's number                                Rock's number" << std::endl;
    for (unsigned int i = 0; i < n_lines; ++i) {
        std::cout << " " <<i+1<<"|  [";
        for (unsigned int k = 0; k < n_rocks[i]; ++k ) {
            std::cout << " " << "* ";
        }
        for (unsigned int k = 0; k < 3*(15 - n_rocks[i]); ++k ) {
            std::cout << " ";
        }
        std::cout << " |" << n_rocks[i] << std::endl;
    }
    std::cout << "============================================================" << std::endl;
}

vector<unsigned int> Opponent(vector<unsigned int> n_rocks) {
    unsigned int n_lines = int( n_rocks.size() );
    vector<unsigned int> n_try_rocks;
    unsigned int nim_sum;

    for (unsigned int i = 0; i < n_lines; ++i ) {
        for (unsigned int k = n_rocks[i]; k > 0; --k ) {
            n_try_rocks = n_rocks;
            n_try_rocks[i] -= k;
            nim_sum = 0;
            //nim_sum = n_try_rocks[0];
            for (unsigned int j = 0; j < n_lines-1; ++j ) {
                nim_sum = nim_sum ^ n_try_rocks[j];
            };
            if ( nim_sum == 0 ) {
                //std::cout << i << " " << k << " " << nim_sum  std::endl;
                return {i, k};
            };
        }
    };
    for (unsigned int i = 0; i < n_lines; ++i ) {
        if ( n_rocks[i] != 0 ) {
            return {i, 1};
        }
    }

}

// int nim_sum(vector<unsigned int> n_rocks) {
//     unsigned int nim_sum = n_rocks[0];
//     unsigned int n_lines = int( n_rocks.size() );
//     for (unsigned int j = 0; j < n_lines-1; ++j ) {
//         nim_sum = nim_sum ^ n_rocks[i];
//     }
// }

vector<unsigned int> Step(vector<unsigned int> line_rocks, vector<unsigned int> n_rocks ) {
    n_rocks[ line_rocks[0] ] -= line_rocks[1] ;
    return n_rocks;
};

bool End(vector<unsigned int> n_rocks) {
    unsigned int line_rocks = int( n_rocks.size() );
    bool Check = 0;
    for (unsigned int i = 0; i < line_rocks ; ++i ) {
        Check = Check || ( n_rocks[i] != 0);
    };
    return !Check;
};

int main() {
    vector<unsigned int> Rocks_num;
    unsigned int n_lines;
    std::cout <<     "-------Enter string and rocks(<16) number with space--------" << std::endl;
    cin >> n_lines;
    unsigned int num;

    for (unsigned int i = 0; (i < n_lines); ++i) {
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

    vector<unsigned int> Steps (2);
    while ( num != 3) {
        if ( num == 1) {
            std::cout <<     "-------Enter string and rocks(<16) number with space--------" << std::endl;
            cin >> Steps[0] >> Steps[1];
            --Steps[0];
            Rocks_num = Step(Steps, Rocks_num);
            std::cout << "Your turn:" << std::endl;
            Interface( Rocks_num );
            if ( End(Rocks_num) ) {
                std::cout << "You are winner!" << std::endl;
                num = 3;
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
                num = 3;
            }
            else {
                num = 1;
            }

            continue;
        }
        
    }
}