from typing import List, Tuple
from collections import deque

def next_step(
    current_board: List[List[str]],
    current_pos: Tuple[int, int],
    all_player_positions: List[Tuple[int, int]],
    your_character: str,
) -> Tuple[int, int]:

    r, c = current_pos
    rows = len(current_board)
    cols = len(current_board[0])

    def in_bounds(nr, nc):
        return 0 <= nr < rows and 0 <= nc < cols

    def is_safe(nr, nc):
        if not in_bounds(nr, nc):
            return False
        return current_board[nr][nc] in (".", your_character)

    moves = [(0,1),(1,0),(0,-1),(-1,0)]

    enemies = [pos for pos in all_player_positions if pos != current_pos]

    for er, ec in enemies:
        if abs(er - r) + abs(ec - c) == 1:
         
            if is_safe(er, ec):
                return (er, ec)


    visited = [[False]*cols for _ in range(rows)]
    q = deque()
    q.append((r, c, []))
    visited[r][c] = True

    while q:
        cr, cc, path = q.popleft()

        if current_board[cr][cc] == "." and (cr, cc) != (r, c):

            return path[0]

        for dr, dc in moves:
            nr, nc = cr + dr, cc + dc
            if in_bounds(nr, nc) and not visited[nr][nc]:
                if is_safe(nr, nc):
                    visited[nr][nc] = True
                    q.append((nr, nc, path + [(nr, nc)]))


    for dr, dc in moves:
        nr, nc = r + dr, c + dc
        if is_safe(nr, nc):
            return (nr, nc)

    return current_pos