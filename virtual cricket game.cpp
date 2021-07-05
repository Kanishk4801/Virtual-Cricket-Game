#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<unistd.h>
#include<vector>
using namespace std;



class Player
{
	public:
		string name;
		int id, runsScored, ballsPlayed, ballsBowled, runsGiven, wicketsTaken;
		
		Player()
		{
			runsScored = 0;
			ballsPlayed = 0;
			ballsBowled = 0;
			runsGiven = 0;
			wicketsTaken = 0;
		}
		
};

class Team
{
	public:
		string name;
		int totalRunsScored, wicketsLost, totalBallsBowled;
		vector<Player> players;
		
		Team()
		{
			totalRunsScored = 0;
			wicketsLost = 0;
			totalBallsBowled = 0;
		}
		
};

class Game
{
	public:
		
		int playersPerTeam, maxBalls, totalPlayers;
		string players[11];
		
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;
		bool isFirstInnings;
		
		Game()
		{
			playersPerTeam = 4;
			maxBalls = 6;
			totalPlayers = 11;
			
			players[0] = "Rohit"; 
			players[1] = "Dhawan";
			players[2] =  "Virat";
			players[3] =  "Rahul";
			players[4] =  "Pant";
			players[5] =  "Dhoni";
			players[6] =  "Pandya";
			players[7] =  "Jadeja";
			players[8] = "Shami";
			players[9] = "Bumrah";
			players[10] = "Kumar";
			
			isFirstInnings = false;
			teamA.name = "Knights";
			teamB.name = "Lions";
		}
		
		void welcomeUser()
		{
			cout << "\t\t---------------------------------------" << endl;
   			cout << "\t\t|============= CRIC - IN =============|" << endl;
    		cout << "\t\t|                                     |" << endl;
    		cout << "\t\t|   Welcome to Virtual Cricket Game   |" << endl;
    		cout << "\t\t---------------------------------------" << endl << endl;
    		
    		cout << "\t\t--------------------------------------------------------" << endl;
    		cout << "\t\t|==================== Instructions ====================|" << endl;
    		cout << "\t\t--------------------------------------------------------" << endl;
    		cout << "\t\t|                                                      |" << endl;
    		cout << "\t\t| 1. Create 2 Teams (with 4 players each) from a given |" << endl;
    		cout << "\t\t|    pool of 11 players.                               |" << endl;
    		cout << "\t\t| 2. Lead the toss and decide the choice of play.      |" << endl;
    		cout << "\t\t| 3. Each innings will be of 6 balls.                  |" << endl;
    		cout << "\t\t--------------------------------------------------------" << endl << endl;
    		
    		cout << "\t\tPress Enter to continue ";
    		cin.get();
		}
	
		void showAllPlayers()
		{
			cout << endl;
			cout << "\t\t---------------------------------------------------" << endl;
			cout << "\t\t|================ Pool of Players ================|" << endl;
			cout << "\t\t---------------------------------------------------" << endl;
			for (int i = 1; i <= 11; i++)
			{
				cout << "\t\t\t[" << i << "] " << players[i - 1] << endl;
			}
			
			cout << "\n\t\tPress Enter to continue ";
			cin.get();
		}
		
		int takeIntegerInput()
		{
			cout<<"\t ";
			int n;
			
			while (! (cin >> n))
			{
				cin.clear();
				cin.ignore(numeric_limits <streamsize> :: max(), '\n');
				cout << "\n\tPlease enter an integer! - ";
			}
			
			return n;
		}
		
		bool validateSelectedPlayer(int index)
		{
			int n;
			vector <Player> playerList;
			
			playerList = teamA.players;
			n = playerList.size();
			
			for(int i = 0; i < n; i++)
			{
				if (playerList[i].id == index)
				return false;
			}
			
			playerList = teamB.players;
			n = playerList.size();
			
			for (int i = 0; i < n; i++)
			{
				if (playerList[i].id == index)
				return false;
			}
			
			return true;
		}
		
		void selectPlayers()
		{
			cout << endl;
			cout << "\t\t----------------------------------------------------------------" << endl;
			cout << "\t\t|============= Create Team Knights and Team Lions =============|" << endl;
			cout << "\t\t----------------------------------------------------------------" << endl;
			cout << endl << "\t\t Please use the player indices given in the Pool of Players to select them!" << endl;
			
			for (int i =1; i<= playersPerTeam; i++)
			{
				TeamASelection:
				cout << "\n\t\t Select player " << i << " of Team Knights - ";
				
				int playerIndexTeamA = takeIntegerInput();
				
				if (playerIndexTeamA <= 0 || playerIndexTeamA > 11)
				{
					cout << "\n\t\tPlease select from the given players! " << endl;
					goto TeamASelection;
				}
				
				else if ( ! validateSelectedPlayer (playerIndexTeamA))
				{
					cout << "\n\t\t Requested player has already been selected! Please select another player. " << endl;
					goto TeamASelection; 
				}
				else
				{
					Player teamAPlayer;
					teamAPlayer.id = playerIndexTeamA;
					teamAPlayer.name = players[playerIndexTeamA - 1];
					teamA.players.push_back(teamAPlayer);
				}
				
				TeamBSelection:
				cout << "\n\t\t Select player " << i << " of Team Lions - ";
				
				int playerIndexTeamB = takeIntegerInput();
				
				if (playerIndexTeamB <= 0 || playerIndexTeamB > 11)
				{
					cout << "\n\t\tPlease select from the given players! " << endl;
					goto TeamBSelection;
				}
				
				else if ( ! validateSelectedPlayer (playerIndexTeamB))
				{
					cout << "\n\t\t Requested player has already been selected! Please select another player. " << endl;
					goto TeamBSelection; 
				}
				
				else
				{
					Player teamBPlayer;
					teamBPlayer.id = playerIndexTeamB;
					teamBPlayer.name = players[playerIndexTeamB - 1];
					teamB.players.push_back(teamBPlayer);
				}
			}
			cin.ignore(numeric_limits <streamsize> :: max(), '\n');
			cout << "\n\t\tSelection of Teams over!" << endl << endl;
			cout << "\t\tPress Enter to continue " << endl << endl;
			cin.get();
		}
		
		void showTeamPlayers()
		{
			cout << "\t\t--------------------------\t\t--------------------------" << endl;
    		cout << "\t\t|======= Knights ========|\t\t|======== Lions =========|" << endl;
    		cout << "\t\t--------------------------\t\t--------------------------" << endl;

    		for (int i = 1; i <= 4; i++) 
			{
        		cout << "\t\t|";
        		cout << "\t[" << i << "] " << teamA.players[i - 1].name << "\t |";
        		cout << "\t\t|\t";
        		cout << "[" << i << "] " << teamB.players[i - 1].name << "\t |";
        		cout << endl;
    		}
    		cout << "\t\t--------------------------\t\t--------------------------" << endl << endl;
		}
		
		void toss()
		{
			cout << "\t \tPress Enter to Toss " << endl << endl;
			cin.get();
			
			cout << "\t\t------------------------------------------------" << endl;
			cout << "\t\t|================= Let's Toss =================|" << endl;
			cout << "\t\t------------------------------------------------" << endl;
			cout<<endl;
			
			cout << "\t\tTossing the coin ......" << endl <<endl;
			usleep (10000 * 1000);
			
			srand(time(NULL)); 
			int coinToss = rand() % 2;
			switch (coinToss)
			{
				case 0: cout << "\t\tTeam Knights won the toss! " << endl << endl;
						tossChoice (teamA);
						break;
				case 1: cout << "\t\tTeam Lions won the toss! " << endl << endl;
						tossChoice (teamB);
						break;
				default: break;
			}
		}
		
		void tossChoice (Team tossWinner)
		{
			cout << "\t\tEnter 1 to bat or 2 to bowl first" << endl;
			cout << "\t\t 1. Bat" << endl;
			cout << "\t\t 2. Bowl" << endl;
			
			int choice = takeIntegerInput();
			cin.ignore(numeric_limits <streamsize> :: max(), '\n');
			cout << endl;
			
			switch(choice)
			{
				case 1: cout << "\t\t Team " << tossWinner.name << " won the toss and elected to Bat first." << endl << endl;
						
						if(tossWinner.name.compare("Knights") == 0)
						{
							battingTeam = &teamA;
							bowlingTeam = &teamB;
						}
						
						else
						{
							battingTeam = &teamB;
							bowlingTeam = &teamA;
						}
						break;
				
				case 2: cout << "\t\t Team " << tossWinner.name << " won the toss and elected to Bowl first." << endl << endl;
						
						if(tossWinner.name.compare("Knights") == 0)
						{
							battingTeam = &teamB;
							bowlingTeam = &teamA;
						}
						
						else
						{
							battingTeam = &teamA;
							bowlingTeam = &teamB;	
						}
						break;
				
				default: cout << "\t\t Please enter 1 or 2 only! " << endl;
						 tossChoice (tossWinner);
						 break;
			}
		}
		
		void startFirstInnings()
		{
			cout << "\t\t\t ||||| FIRST INNINGS STARTS |||||" << endl << endl;
			
			isFirstInnings = true;
			
			initialisePlayers();
		}
		
		void initialisePlayers()
		{
			batsman = &battingTeam->players[0];
			bowler = &bowlingTeam->players[0];
		
			cout << "\t\t Team " << battingTeam->name << " - " << batsman->name << " is Batting." << endl;
			cout << "\t\t Team " << bowlingTeam->name << " - " << bowler->name << " is Bowling. " << endl << endl;
		}
		
		void playInnings()
		{
			for (int i = 0; i < maxBalls; i++)
			{
				cout << "\t\tPress Enter to Bowl......" << endl;
				cin.get();
				cout << "\t\tBowling.... " << endl << endl;
				bat();
				
				if (! validateInnings())
				break;
				

			}
			
		}	
			
		void bat()
		{
			srand(time(NULL));
			int runs = rand()%7;
			
			batsman->runsScored += runs;
			batsman->ballsPlayed += 1;
			battingTeam->totalRunsScored += runs;
			
			bowler->ballsBowled += 1;
			bowler->runsGiven += runs;
			bowlingTeam->totalBallsBowled += 1;
			
			if(runs == 0)
			{
				cout << "\t\tBall number " << bowlingTeam->totalBallsBowled << ": " << bowler->name << " to " << batsman->name << ", OUT! " << endl << endl;
				battingTeam->wicketsLost += 1;
				bowler->wicketsTaken += 1;
				showGameScorecard();
				
				batsman = &battingTeam->players[battingTeam->wicketsLost];
			}
			
			else
			{
				cout << "\t\tBall number " << bowlingTeam->totalBallsBowled << ": " << bowler->name << " to " << batsman->name << ", " << runs << " runs!" << endl << endl;
				showGameScorecard();
			}
		}	
		
		bool validateInnings()
		{
			if (isFirstInnings)
			{
				if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
				{
					cout << "\t\t\t ||||| FIRST INNINGS ENDS |||||" << endl << endl;
					cout << "\t\t" << battingTeam->name << " : " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << endl;
					cout << "\t\t" << bowlingTeam->name << " needs " << battingTeam->totalRunsScored+1 << " runs to win !!" << endl << endl; 
				
					return false;
				}
				else
				return true;
			}
			else
			{
				if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls || battingTeam->totalRunsScored > bowlingTeam->totalRunsScored)
				{
					cout << "\t\t\t ||||| SECOND INNINGS ENDS ||||| " << endl << endl;
					cout << "\t\t" << battingTeam->name << " : " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << endl;
					
					return false;
				}
				else
				return true;
			}	
		}
		
		void showGameScorecard()
		{
			cout << "\t\t-------------------------------------------------------------------------------------------" << endl;
			cout << "\t\t|   " << battingTeam->name << ": " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") \t";
			cout << "\t\t| " << batsman->name << ": " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t\t " << bowler->name << ": " << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << endl;
			cout << "\t\t-------------------------------------------------------------------------------------------" << endl << endl;
		}
		
		void startSecondInnings()
		{
			cout << "\t\t\t ||||| SECOND INNINGS STARTS |||||" << endl << endl;
			
			isFirstInnings = false;
			
			
			Team *temp;
			temp = battingTeam;
			battingTeam = bowlingTeam;
			bowlingTeam = temp;
			
			initialisePlayers();
		}
		
		void decideWinner()
		{
			if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored)
				cout << "\n\t\t " << battingTeam->name << " WON THE MATCH BY "<< playersPerTeam - battingTeam->wicketsLost << " WICKETS!!!" << endl << endl;
				
			else if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored)
				cout << "\n\t\t " << bowlingTeam->name << " WON THE MATCH BY "<< bowlingTeam->totalRunsScored - battingTeam->totalRunsScored << " RUNS!!!" << endl << endl;
			else
				cout << "\n\t\tMATCH IS A DRAW!!!" << endl << endl;
			cout << "\t\t\t ||||| MATCH ENDS |||||" << endl << endl;
		}
		
		void matchSummary()
		{
			cout << "\n\t\t\t" << bowlingTeam->name << ": " << bowlingTeam->totalRunsScored << " - " << bowlingTeam->wicketsLost << "  (" << battingTeam->totalBallsBowled << ") " << endl << endl;
			
			cout << "\t\t\t=============================================================================" << endl;
			cout << "\t\t\t|      PLAYER                   BATTING                   BOWLING           |" <<endl;
			cout << "\t\t\t|---------------------------------------------------------------------------|" << endl;
			for (int i = 1; i <= 4; i++)
			{ 
				cout << "\t\t\t|   [" << i << "] " << bowlingTeam->players[i-1].name <<"\t\t\t"<< bowlingTeam->players[i-1].runsScored << "(" << bowlingTeam->players[i-1].ballsPlayed << ")\t\t\t" << bowlingTeam->players[i-1].ballsBowled << " - " << bowlingTeam->players[i-1].runsGiven << " - " << bowlingTeam->players[i-1].wicketsTaken <<" \t    |" << endl;
				
			}
			cout << "\t\t\t=============================================================================" << endl << endl;
			
				cout << "\n\t\t\t" << battingTeam->name << ": " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << "  (" << bowlingTeam->totalBallsBowled << ") " << endl << endl;
			
			cout << "\t\t\t============================================================================" << endl;
			cout << "\t\t\t|      PLAYER                   BATTING                   BOWLING          |" <<endl;
			cout << "\t\t\t|--------------------------------------------------------------------------|" << endl;
			for (int i = 1; i <= 4; i++)
			{
				cout << "\t\t\t|   [" << i << "] " << battingTeam->players[i-1].name <<"\t\t\t"<< battingTeam->players[i-1].runsScored << "(" << battingTeam->players[i-1].ballsPlayed << ")\t\t\t" << battingTeam->players[i-1].ballsBowled << " - " << battingTeam->players[i-1].runsGiven << " - " << battingTeam->players[i-1].wicketsTaken <<" \t   |" << endl;
				
			}
			cout << "\t\t\t============================================================================" << endl << endl;
		}
		
	
	
	
};

int main()
{
	Game game;
	game.welcomeUser();
	game.showAllPlayers(); 
	game.selectPlayers();
	game.showTeamPlayers();
	game.toss();
	game.startFirstInnings();
	game.playInnings();
	game.startSecondInnings();
	game.playInnings();
	game.decideWinner();
	game.matchSummary();
	return 0;
}




































