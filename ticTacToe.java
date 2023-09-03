import java.util.Scanner;

public class ticTacToe {
    // The board to store the state of the game
    private char[][] board;
    // Current player (either 'X' or 'O')
    private char currentPlayer;
    // Number of moves played so far
    private int moves;

    public ticTacToe() {
        board = new char[3][3];
        currentPlayer = 'X';
        moves = 0;
        initializeBoard();
    }
        
    // ANSI escape codes for setting text colors
    private static final String ANSI_RESET = "\u001B[0m";
    private static final String ANSI_RED = "\u001B[31m";
    private static final String ANSI_BLUE = "\u001B[34m";

     
    // Initialize the board with empty cells
    private void initializeBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    // Print the current state of the board
    private void printBoard() {
        System.out.println("-------------");
        for (int i = 0; i < 3; i++) {
            System.out.print("| ");
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    System.out.print(ANSI_RED + board[i][j] + ANSI_RESET + " | ");
                } else if (board[i][j] == 'O') {
                    System.out.print(ANSI_BLUE + board[i][j] + ANSI_RESET + " | ");
                } else {
                    System.out.print(board[i][j] + " | ");
                }
            }
            System.out.println();
            System.out.println("-------------");
        }
    }

    // Get input from the current player for their move
    private void makeMove() {
        Scanner scanner = new Scanner(System.in);
        int row, col;

        do {
            System.out.println("Player " + currentPlayer + ", enter your move (row [1-3] and column [1-3]): ");
            row = scanner.nextInt() - 1;
            col = scanner.nextInt() - 1;
        } while (!isValidMove(row, col));

        board[row][col] = currentPlayer;
        moves++;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Check if the given move is valid (within the board and the cell is empty)
    private boolean isValidMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            System.out.println("Invalid move. Row and column should be between 1 and 3.");
            return false;
        }

        if (board[row][col] != ' ') {
            System.out.println("Invalid move. The cell is already taken.");
            return false;
        }

        return true;
    }

    // Check if the game has been won
    private boolean checkWin() {
        // Check rows, columns, and diagonals for three consecutive symbols
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                return true; // Row win
            }

            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                return true; // Column win
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
            return true; // Diagonal win (top-left to bottom-right)
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
            return true; // Diagonal win (top-right to bottom-left)
        }

        return false;
    }

    // Check if the game is a draw (all cells are filled)
    private boolean checkDraw() {
        return moves == 9;
    }

    public void play() {
        System.out.println("Let's play Tic Tac Toe!");
        printBoard();

        Scanner scanner = new Scanner(System.in);

        while (true) {
            makeMove();
            printBoard();

            if (checkWin()) {
                System.out.println("Player " + currentPlayer + " wins!");
                break;
            } else if (checkDraw()) {
                System.out.println("It's a draw!");
                break;
            }
        }
        scanner.close(); // Close the Scanner after the game is over
        System.out.println("Game Over.");
    }

    public static void main(String[] args) {
        ticTacToe game = new ticTacToe();
        game.play();
    }
}
