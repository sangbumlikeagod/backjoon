package Algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Jun16985_Maaaaaaaaaze {
    
    private static Boolean[][][] maze = new Boolean[5][5][5];  // 조립되는 큐브
    private static Boolean[][][][] plate = new Boolean[5][4][5][5];  // 1 : 판 no, 2 : 회전 수, 3 : x, 4 : y
    private static boolean[][][] visited;
    private static Integer[] turns = new Integer[5];
    private static Integer[] orders = new Integer[5];
    private static boolean[] isSelected = new boolean[5];
    private static int answer = Integer.MAX_VALUE;
    private static final int[][] MOVE_DIRS = {{-1,0,0},{0,-1,0},{0,0,-1},{1,0,0},{0,1,0},{0,0,1}};
    private static final PositionIn3dim START = new PositionIn3dim(0,0,0);
    private static final PositionIn3dim END = new PositionIn3dim(4,4,4);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for (int plateNo = 0; plateNo < 5; plateNo++) {
            for (int row = 0; row < 5; row++) {
                st = new StringTokenizer(br.readLine(), " ");
                for (int col = 0; col < 5; col++) {
                    plate[plateNo][0][row][col] = Objects.equals(st.nextToken(), "1");
                }
            }

            for (int turns = 1; turns < 4; turns++) {
                storeRotatedPlate(plateNo, turns);
            }
        }

        changeOrder(0);
        System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
    }


    private static void storeRotatedPlate(int plateNo, int turns) {
        Boolean[][] rotated = new Boolean[5][5];
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                rotated[4-col][row] = plate[plateNo][turns-1][row][col];
            }
        }

        plate[plateNo][turns] = rotated;
    }

    private static void changeOrder(int depth) {
        if (depth == 5) return;

        for (int plateNo = 0; plateNo < 5; plateNo++) {
            if (isSelected[plateNo]) continue;

            orders[depth] = plateNo;
            isSelected[plateNo] = true;

            if (depth == 4) rotatePlate(0);

            changeOrder(depth+1);
            isSelected[plateNo] = false;
        }
    }

    private static void rotatePlate(int depth) {
        if (depth == 5) return;

        for (int turn = 0; turn < 4; turn++) {
            turns[depth] = turn;

            if (depth == 4) {
                assemblyPlate();

                int moves = BFS();
                if (moves != Integer.MAX_VALUE) {
                    System.out.print("  moves = " + moves + "\n");
                }
                answer = Math.min(answer, moves);
            }
            rotatePlate(depth+1);
        }

    }

    private static void assemblyPlate() {
        for (int idx = 0; idx < 5; idx++) {
            maze[idx] = plate[orders[idx]][turns[orders[idx]]];
        }
    }

    private static int BFS() {
        Queue<PositionIn3dim> queue = new ArrayDeque<>();
        visited = new boolean[5][5][5];

        queue.add(START);
        visited[START.x][START.y][START.z] = true;
        int moves = -1;

        while (!queue.isEmpty()) {
            int size = queue.size();
            moves++;

            while (size-- > 0) {
                PositionIn3dim cur = queue.poll();

                if (determineArrival(cur.x, cur.y, cur.z)) return moves;

                for (int dir = 0; dir < 6; dir++) {
                    Integer next_x = cur.x + MOVE_DIRS[dir][0];
                    Integer next_y = cur.y + MOVE_DIRS[dir][1];
                    Integer next_z = cur.z + MOVE_DIRS[dir][2];

                    if (canMove(next_x, next_y, next_z)) {
                        queue.add(new PositionIn3dim(next_x, next_y, next_z));
                        visited[next_x][next_y][next_z] = true;
                    }
                }
            }
        }

        return Integer.MAX_VALUE;
    }

    private static boolean canMove(Integer x, Integer y, Integer z) {
        return 0<=x && x<5 && 0<=y && y<5 && 0<=z && z<5
                && !visited[x][y][z] && maze[x][y][z];
    }

    private static boolean determineArrival(Integer x, Integer y, Integer z) {
        return Objects.equals(x, END.x) && Objects.equals(y, END.y) && Objects.equals(z, END.z);
    }

    private static class PositionIn3dim {
        private Integer x;
        private Integer y;
        private Integer z;

        public PositionIn3dim(Integer x, Integer y, Integer z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
}