
//
//  checkers.cpp
//  
//
//  Created by Livingston Albritten on 1/25/16.
//
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

int main() 
{
    
    class Board {
        public:
            string brd[64];
            int w_cnt;
            int r_cnt;
            int moves;
            bool jump_req;
            int req_jump;
            int a_sp[32] = {1, 3, 5, 7, 8, 10, 12, 14, 17, 19, 21, 23, 24, 26, 28, 30, 33, 35, 37, 39, 40, 42, 44, 46, 49, 51, 53, 55, 56, 58, 60, 62};
        
            Board() {
                moves = 0;
                w_cnt = 12;
                r_cnt = 12;

                for (int i = 0; i < 64; i++) {
                     this->brd[i] =  "N";
                }
            
                // set up checkerboard.
                this->brd[1] = "w1";
                this->brd[3] = "w2";
                this->brd[5] = "w3";
                this->brd[7]=  "w4";
            
                this->brd[8] = "w5";
                this->brd[10] = "w6";
                this->brd[12] = "w7";
                this->brd[14] = "w8";
            
                this->brd[17] = "w9";
                this->brd[19] = "w10";
                this->brd[21] = "w11";
                this->brd[23] = "w12";
            
            
            
            
                this->brd[40] = "r1";
                this->brd[42] = "r2";
                this->brd[44] = "r3";
                this->brd[46] = "r4";
                
                this->brd[49] = "r5";
                this->brd[51] = "r6";
                this->brd[53] = "r7";
                this->brd[55] = "r8";
            
                this->brd[56] = "r9";
                this->brd[58] = "r10";
                this->brd[60] = "r11";
                this->brd[62] = "r12";
            }
        
            void get_board() {
                //return this->brd;
                for (int i = 0; i < 64; i++ ) {
                    if (this->brd[i].at(0) == 'w' && (i == 56 || i == 58 || i == 60 || i == 62)) {
                        this->brd[i] = "K" + this->brd[i];
                    }
                    else if(this->brd[i].at(0) == 'r' && (i == 1 || i == 3 || i == 5 || i == 7)) {
                        this->brd[i] = "K" + this->brd[i];
                    }
                    if (i%8 == 7) {
                        cout << this->brd[i] << "\n" ;
                    }
                    else {
                        cout << this->brd[i] << char(32) << char(32) ;

                    }
                }
            }
            void king_count_cng(char c) {
                if (c == 'w') {
                    this->r_cnt -= 1;
                }
                else {
                    this->w_cnt -= 1;
                }
            }
            /*int check_jumps(char c) {
                int chk[12], count, jmp1, jmp2;
                count = 0;
                for (int i = 0; i < 64; i++) {
                    if ((this->brd[i].at(0) == c || this->brd[i].at(1) == c)) {
                        chk[count] = i;
                        count += 1;
                    }
                }
                if (c == 'w') {
                    jmp1 = a + 7;
                    jmp2 = a + 9;
                    if (find(begin(this->a_sp),  end(this->a_sp), acc1) ==  end(this->a_sp)) {
                        acc1 = 64;
                    }
                    else if (find(begin(this->a_sp),  end(this->a_sp), acc2) ==  end(this->a_sp)) {
                        acc2 = 64;
                    }
                }
            }*/
        
        
            void move_checker(int a, int b) {
                this->moves += 1;
                // move checker from spot a to b
                
                // tke is jumped spott, acc1, acc2 are acceptable next moves
                // c is the color of the checker being moved
                // o_c is jumped checker-if it exists
                
                int tke, acc1, acc2, acc3, acc4, nb, na, nacc1, nacc2, nacc3, nacc4, ntke, ontke, ntke1, ontke1, Ktke[4];
                char c, o_c, kc;
                bool one, jump, n_one;
                c = this->brd[a].at(0);
                

                    
                    
                // make sure a and b are both in the list of acceptable spaces, and that b is empty
                if(find(begin(this->a_sp), end(this->a_sp), a) != end(this->a_sp) && find(begin(this->a_sp),  end(this->a_sp), b) !=  end(this->a_sp) && this->brd[b] == "N") {
                    
                        
                    // note color to determine acceptable moves.
                    if (c == 'w') {
                        
                        // determine if it is a jump or not
                        if (b - a > 13) {
                            jump = true;
                            // note acceptable jumps.
                            acc1 = a + 14;
                            acc2 = a + 18;
                            if (find( begin(this->a_sp),  end(this->a_sp), acc1) ==  end(this->a_sp)) {
                                acc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc2) ==  end(this->a_sp)) {
                                acc2 = 64;
                            }
                            // if b is an acceptable jump, and enemy checker in tke, move checker and remove jumped checker.
                            tke = (a + b)/2;
                            if ((b == acc2 || b == acc1) && (this->brd[tke].at(0) == 'r' || this->brd[tke].at(1)== 'r')) {
                                this->r_cnt -= 1;
                                this->brd[b] = this->brd[a];
                                this->brd[a] = "N";
                                this->brd[tke] = "N";
                            }
                            else {
                                cout << "Invalid jump.";
                            }
                            
                            //note ending position, if another jump is available, moves must be made. If other player has jump, note for his move.
                            na = b;
                            // note possible acceptable jumps.
                            nacc1 = a + 14;
                            nacc2 = a + 18;
                            if (find( begin(this->a_sp),  end(this->a_sp), nacc1) ==  end(this->a_sp)) {
                                nacc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), nacc2) ==  end(this->a_sp)) {
                                nacc2 = 64;
                            }
                            if ((nacc1 == 64 || nacc2 == 64) && ! (nacc1 == 64 && nacc2 == 64) ) {
                                n_one = true;
                            }
                            // check if ntke has enemy checker.
                            if (n_one == true) {
                                ntke = (nacc1 + na)/2;
                                // if spot not empty, continue
                                if (this->brd[ntke] != "N") {
                                    //if enemy checker, take.
                                    if (this->brd[ntke].at(0) == 'r'|| this->brd[ntke].at(1) == 'r') {
                                        nb = ntke;
                                        move_checker(na, nb);
                                    }
                                        // if not, stay.
                                }
                            }
                            else if (n_one == false) {
                                ntke = (nacc1 + na)/2;
                                ontke = (nacc2 + na)/2;
                                // if both have enemy checker
                                if ((this->brd[ntke].at(0) ==  'r' || this->brd[ntke].at(1) == 'r') && (this->brd[ontke].at(0) == 'r' || this->brd[ontke].at(1) == 'r')) {
                                    cout << "You can either jump checker in spot" << ntke << "or spot" << ontke << ". Pick one.";
                                    cin >> nb;
                                    move_checker(na, nb);
                                }
                                // if one has enemy checker
                                else if ((this->brd[ntke].at(0) == 'r' || this->brd[ntke].at(1) =='r') && this->brd[ontke] == "N") {
                                    move_checker(na, ntke);
                                }
                                else if (this->brd[ntke] == "N" && (this->brd[ontke].at(0) == 'r' || this->brd[ontke].at(1) == 'r')) {
                                    move_checker(na, ontke);
                                }
                            }
                        }
                        // if it is not a jump
                        else {
                            jump = false;
                            // note acceptable next moves
                            acc1 = a + 7;
                            acc2 = a + 9;
                            if (find( begin(this->a_sp),  end(this->a_sp), acc1) ==  end(this->a_sp)) {
                                acc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc2) ==  end(this->a_sp)) {
                                acc2 = 64;
                            }
                            if (acc1 == 64 || acc2 == 64) {
                                one = true;
                            }
                            // make sure b is an acceptable move.
                            if (b == acc1 || b == acc2) {
                                // if b is empty, move checker.
                                if (this->brd[b] == "N") {
                                    this->brd[b] = this->brd[a];
                                    this->brd[a] =  "N";
                                    // if b is not empty, throw error.
                                }
                                else {
                                    cout << "Invalid move.";
                                }
                            }
                            // note ending position.
                            na = b;
                            // note possible jumps.
                            nacc1 = a + 14;
                            nacc2 = a + 18;
                            
                            if (find( begin(this->a_sp),  end(this->a_sp), nacc1) ==  end(this->a_sp)) {
                                nacc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), nacc2) ==  end(this->a_sp)) {
                                nacc2 = 64;
                            };
                            if (nacc1 == 64 || nacc2 == 64) {
                                n_one = true;
                            }
                            // check if ntke has enemy checker.
                            if (n_one == true) {
                                ntke = (nacc1 + na)/2;
                                // if spot empty, continue
                                if (this->brd[ntke] == "N") {
                                    //if enemy checker, take.
                                    if (this->brd[ntke].at(0) == 'r'|| this->brd[ntke].at(1) == 'r') {
                                        nb = ntke;
                                        move_checker(na, nb);
                                    }
                                    // if not, stay.
                                }
                            }
                            else if (n_one == false) {
                                ntke = (nacc1 + na)/2;
                                ontke = (nacc2 + na)/2;
                                // if both have enemy checker
                                if ((this->brd[ntke].at(0) ==  'r' || this->brd[ntke].at(1) == 'r') && (this->brd[ontke].at(0) == 'r' || this->brd[ontke].at(1) == 'r')) {
                                    cout << "You can either jump checker in spot" << ntke << "or spot" << ontke << ". Pick one.";
                                    cin >> nb;
                                    move_checker(na, nb);
                                }
                                // if one has enemy checker
                                else if ((this->brd[ntke].at(0) == 'r' || this->brd[ntke].at(1) =='r') && this->brd[ontke] == "N") {
                                    move_checker(na, ntke);
                                }
                                else if (this->brd[ntke] == "N" && (this->brd[ontke].at(0) == 'r' || this->brd[ontke].at(1) == 'r')) {
                                    move_checker(na, ontke);
                                }
                            }
                        }
                    }
                    else if (c == 'r') {
                        // determine if it is a jump or not
                        if (13 < (a - b)) {
                            jump = true;
                            // note acceptable jumps.
                            acc1 = a - 14;
                            acc2 = a - 18;
                            if (find( begin(this->a_sp),  end(this->a_sp), acc1) ==  end(this->a_sp)) {
                                acc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc2) ==  end(this->a_sp)) {
                                acc2 = 64;
                            }
                            // if b is an acceptable jump, and enemy checker in tke, move checker and remove jumped checker.
                            tke = (a + b)/2;
                            if ((b == acc2 || b == acc1) && (this->brd[tke].at(0) == 'w' || this->brd[tke].at(1) == 'w')) {
                                this->w_cnt -= 1;
                                this->brd[b] = this->brd[a];
                                this->brd[a] = "N";
                                this->brd[tke] = "N";
                            }
                            else {
                                cout << "Invalid jump.";
                            }
                            //note ending position, if another jump is available, moves must be made. If other player has jump, note for his move.
                            na = b;
                            // note possible acceptable jumps.
                            nacc1 = a - 14;
                            nacc2 = a - 18;
                            if (find( begin(this->a_sp),  end(this->a_sp), nacc1) ==  end(this->a_sp)) {
                                nacc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), nacc2) ==  end(this->a_sp)) {
                                nacc2 = 64;
                            }
                            if (nacc1 == 64 || nacc2 == 64) {
                                n_one = true;
                            }
                            // check if ntke has enemy checker.
                            if (n_one == true) {
                                ntke = (nacc1 + na)/2;
                                // if spot not empty, continue
                                if (this->brd[ntke] != "N") {
                                    //if enemy checker, take.
                                    if (this->brd[ntke].at(0) == 'w'|| this->brd[ntke].at(1) == 'w') {
                                        nb = ntke;
                                        move_checker(na, nb);
                                    }
                                    // if not, stay.
                                }
                            }
                            else if (n_one == false) {
                                ntke = (nacc1 + na)/2;
                                ontke = (nacc2 + na)/2;
                                // if both have enemy checker
                                if ((this->brd[ntke].at(0) ==  'w' || this->brd[ntke].at(1) == 'w') && (this->brd[ontke].at(0) == 'w' || this->brd[ontke].at(1) == 'w')) {
                                    cout << "You can either jump checker in spot" << ntke << "or spot" << ontke << ". Pick one.";
                                    cin >> nb;
                                    move_checker(na, nb);
                                }
                                // if one has enemy checker
                                else if ((this->brd[ntke].at(0) == 'w' || this->brd[ntke].at(1) =='w') && this->brd[ontke] == "N") {
                                    move_checker(na, ntke);
                                }
                                else if (this->brd[ntke] == "N" && (this->brd[ontke].at(0) == 'w' || this->brd[ontke].at(1) == 'w')) {
                                    move_checker(na, ontke);
                                }
                            }
                        }
                        // if it is not a jump
                        else {
                            jump = false;
                            // note acceptable next moves
                            acc1 = a - 7;
                            acc2 = a - 9;
                            if (find( begin(this->a_sp),  end(this->a_sp), acc1) ==  end(this->a_sp)) {
                                acc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc2) ==  end(this->a_sp)) {
                                acc2 = 64;
                            }
                            if (acc1 == 64 || acc2 == 64) {
                                one = true;
                            }
                            // make sure b is an acceptable move.
                            if (b == acc1 || b == acc2) {
                                // if b is empty, move checker.
                                if (this->brd[b] == "N") {
                                    this->brd[b] = this->brd[a];
                                    this->brd[a] =  "N";
                                    // if b is not empty, throw error.
                                }
                                else {
                                    cout << "Invalid move.";
                                }
                            }
                            // note ending position.
                            na = b;
                            // note possible jumps.
                            nacc1 = a - 14;
                            nacc2 = a - 18;
                            
                            if (find( begin(this->a_sp),  end(this->a_sp), nacc1) ==  end(this->a_sp)) {
                                nacc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), nacc2) ==  end(this->a_sp)) {
                                nacc2 = 64;
                            };
                            if (nacc1 == 64 || nacc2 == 64) {
                                n_one = true;
                            }
                            // check if ntke has enemy checker.
                            if (n_one == true && nacc1 != 64) {
                                ntke = (nacc1 + na)/2;
                                // if spot not empty, continue
                                if (this->brd[ntke] != "N") {
                                    //if enemy checker, take.
                                    if (this->brd[ntke].at(0) == 'w'|| this->brd[ntke].at(1) == 'w') {
                                        nb = ntke;
                                        move_checker(na, nb);
                                    }
                                    // if not, stay.
                                }
                            }
                            else if (n_one == false) {
                                ntke = (nacc1 + na)/2;
                                ontke = (nacc2 + na)/2;
                                // if both have enemy checker
                                if ((this->brd[ntke].at(0) ==  'w' || this->brd[ntke].at(1) == 'w') && (this->brd[ontke].at(0) == 'w' || this->brd[ontke].at(1) == 'w')) {
                                    cout << "You can either jump checker in spot" << ntke << "or spot" << ontke << ". Pick one.";
                                    cin >> nb;
                                    move_checker(na, nb);
                                }
                                // if one has enemy checker
                                else if ((this->brd[ntke].at(0) == 'w' || this->brd[ntke].at(1) =='w') && this->brd[ontke] == "N") {
                                    move_checker(na, ntke);
                                }
                                else if (this->brd[ntke] == "N" && (this->brd[ontke].at(0) == 'w' || this->brd[ontke].at(1) == 'w')) {
                                    move_checker(na, ontke);
                                }
                            }
                        }
                    }
                    else if (c == 'K') {
                        kc = this->brd[a].at(1);
                        // determine if it is a jump or not
                        if (13 < abs(a - b)) {
                            jump = true;
                            // note acceptable jumps.
                            acc1 = a - 14;
                            acc2 = a - 18;
                            acc3 = a + 14;
                            acc4 = a + 18;
                            if (find( begin(this->a_sp),  end(this->a_sp), acc1) ==  end(this->a_sp)) {
                                acc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc2) ==  end(this->a_sp)) {
                                acc2 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc3) ==  end(this->a_sp)) {
                                acc3 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc4) ==  end(this->a_sp)) {
                                acc4 = 64;
                            }
                            // if b is an acceptable jump, and enemy checker in tke, move checker and remove jumped checker.
                            tke = (a + b)/2;
                            if ((b == nacc2 || b == nacc1 || b == nacc3 || b == nacc4) && (this->brd[tke] != "N") && (this->brd[tke].at(0) != kc || this->brd[tke].at(1) != kc)) {
                                this->king_count_cng(kc);
                                this->brd[b] = this->brd[a];
                                this->brd[a] = "N";
                                this->brd[tke] = "N";
                            }
                            else {
                                cout << "Invalid jump.";
                            }
                            //note ending position, if another jump is available, moves must be made. If other player has jump, note for his move.
                            na = b;
                            // initialize all possible ntke's that could have enemy checkers.
                            ntke = a - 7;
                            ontke = a - 9;
                            ntke1 = a + 7;
                            ontke1 = a + 9;
                            //check that ntke's are valid moves.
                            if (find( begin(this->a_sp),  end(this->a_sp), ntke) ==  end(this->a_sp)) {
                                ntke = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), ontke) ==  end(this->a_sp)) {
                                ontke = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), ntke1) ==  end(this->a_sp)) {
                                ntke1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), ontke1) ==  end(this->a_sp)) {
                                ontke1 = 64;
                            }
                            for (int i = 0; i < 4; i++) {
                                Ktke[i] = 0;
                            }
                            // add valid ntke's to Ktke
                            if (ntke != 64 && (this->brd[ntke].at(0) == kc || this->brd[ntke].at(1) == kc)) {
                                Ktke[0] = ntke;
                            }
                            else if (ontke != 64 && (this->brd[ontke].at(0) == kc || this->brd[ontke].at(1) == kc)) {
                                Ktke[1] = ontke;
                            }
                            else if (ntke1 != 64 && (this->brd[ntke1].at(0) == kc || this->brd[ntke1].at(1) == kc)) {
                                Ktke[2] = ntke1;
                            }
                            else if (ontke1 != 64 && (this->brd[ontke1].at(0) == kc || this->brd[ontke1].at(1) == kc)) {
                                Ktke[3] = ontke1;
                            }
                            int ktke_cnt = 0;
                            for (int i = 0; i < 4; i++) {
                                if  (Ktke[i] != 0) {
                                    ktke_cnt += 1;
                                    nb = Ktke[i];
                                }
                            }
                            if (ktke_cnt == 1) {
                                move_checker(na, nb);
                            }
                            else if (ktke_cnt > 1) {
                                cout << "You have a multiple possible jumps with the King in space" << na << ". You must choose one of them.";
                            }
                            else {
                                //end move.
                            }
                            
                            
                            if (n_one == true) {
                                ntke = (nacc1 + na)/2;
                                // if spot not empty, continue
                                if (this->brd[ntke] != "N") {
                                    //if enemy checker, take.
                                    if (this->brd[ntke].at(0) == 'w'|| this->brd[ntke].at(1) == 'w') {
                                        nb = ntke;
                                        move_checker(na, nb);
                                    }
                                    // if not, stay.
                                }
                            }
                        }
                        // if it is not a jump
                        if (abs(a-b) < 13) {
                            jump = false;
                            // note acceptable next moves
                            acc1 = a - 7;
                            acc2 = a - 9;
                            acc3 = a + 7;
                            acc4 = a + 9;
                            if (find( begin(this->a_sp),  end(this->a_sp), acc1) ==  end(this->a_sp)) {
                                acc1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc2) ==  end(this->a_sp)) {
                                acc2 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc3) ==  end(this->a_sp)) {
                                acc3 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), acc4) ==  end(this->a_sp)) {
                                acc4 = 64;
                            }
                            // make sure b is an acceptable move.
                            if (b == acc1 || b == acc2 || b == acc3 || b == acc4) {
                                // if b is empty, move checker.
                                if (this->brd[b] == "N") {
                                    this->brd[b] = this->brd[a];
                                    this->brd[a] =  "N";
                                    // if b is not empty, throw error.
                                }
                                else {
                                    cout << "Invalid move.";
                                }
                            }
                            // note ending position.
                            na = b;
                            // initialize all possible ntke's that could have enemy checkers.
                            ntke = na - 7;
                            ontke = na - 9;
                            ntke1 = na + 7;
                            ontke1 = na + 9;
                            //check that ntke's are valid moves.
                            if (find( begin(this->a_sp),  end(this->a_sp), ntke) ==  end(this->a_sp)) {
                                ntke = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), ontke) ==  end(this->a_sp)) {
                                ontke = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), ntke1) ==  end(this->a_sp)) {
                                ntke1 = 64;
                            }
                            else if (find( begin(this->a_sp),  end(this->a_sp), ontke1) ==  end(this->a_sp)) {
                                ontke1 = 64;
                            }
                            for (int i = 0; i < 4; i++) {
                                Ktke[i] = 0;
                            }
                            // add valid ntke's to Ktke
                            if (ntke != 64 && (this->brd[ntke].at(0) == kc || this->brd[ntke].at(1) == kc)) {
                                Ktke[0] = ntke;
                            }
                            else if (ontke != 64 && (this->brd[ontke].at(0) == kc || this->brd[ontke].at(1) == kc)) {
                                Ktke[1] = ontke;
                            }
                            else if (ntke1 != 64 && (this->brd[ntke1].at(0) == kc || this->brd[ntke1].at(1) == kc)) {
                                Ktke[2] = ntke1;
                            }
                            else if (ontke1 != 64 && (this->brd[ontke1].at(0) == kc || this->brd[ontke1].at(1) == kc)) {
                                Ktke[3] = ontke1;
                            }
                            int ktke_cnt = 0;
                            for (int i = 0; i < 4; i++) {
                                if  (Ktke[i] != 0) {
                                    ktke_cnt += 1;
                                    nb = Ktke[i];
                                }
                            }
                            if (ktke_cnt == 1) {
                                move_checker(na, nb);
                            }
                            else if (ktke_cnt > 1) {
                                cout << "You have a multiple possible jumps with the King in space" << na << ". You must choose one of them.";
                            }
                        }                      
                    }
                }
            }
        };
    
        Board B;
        /*B.get_board();
        cout << "\n";
        B.move_checker(17, 24);
        B.get_board();
        cout << "\n";
        B.move_checker(42, 33);
        B.move_checker(24, 42);
        B.get_board();
        cout << "\n" ;
        B.move_checker(40, 33);
        B.move_checker(49, 40);
        B.move_checker(56, 49);
        B.move_checker(42, 56);
        B.get_board();
        cout << "\n" ;
        B.move_checker(56, 49);
        B.move_checker(49, 42);
        B.move_checker(42, 24);
        B.get_board();*/
    
        while (B.w_cnt > 0 && B.r_cnt > 0) {
            int a, b;
            cin >> a >> b;
            B.move_checker(a, b);
            B.get_board();
            cout << "\n";
        }
    
    
    
    
    
}




