from typing import List, Tuple
from collections import deque

DIRS = [(1, 0), (-1, 0), (0, 1), (0, -1)]
N = 50


def inside(x, y):
    return 0 <= x < N and 0 <= y < N


def is_enemy(cell, your_character):
    return cell != "." and cell != your_character


def bfs_space(board, start, your_character):
    """Cuánto espacio puedes alcanzar sin morir"""
    q = deque([start])
    vis = set([start])
    count = 0

    while q:
        x, y = q.popleft()
        count += 1

        for dx, dy in DIRS:
            nx, ny = x + dx, y + dy
            if not inside(nx, ny):
                continue
            if (nx, ny) in vis:
                continue
            if is_enemy(board[nx][ny], your_character):
                continue

            vis.add((nx, ny))
            q.append((nx, ny))

    return count


def dist_to_nearest_enemy(pos, enemies):
    x, y = pos
    best = 10**9
    for ex, ey in enemies:
        best = min(best, abs(x - ex) + abs(y - ey))
    return best


def next_step(
    current_board: List[List[str]],
    current_pos: Tuple[int, int],
    all_player_positions: List[Tuple[int, int]],
    your_character: str,
) -> Tuple[int, int]:

    x, y = current_pos

    enemies = [p for p in all_player_positions if p != current_pos]

    best_move = current_pos
    best_score = -10**18

    for dx, dy in DIRS:
        nx, ny = x + dx, y + dy

        # ❌ movimiento inválido
        if not inside(nx, ny):
            continue

        cell = current_board[nx][ny]

        # ❌ pisar enemigo = muerte
        if is_enemy(cell, your_character):
            continue

        # ⚠️ calcular score
        score = 0

        # 🟢 preferir nuevas celdas
        if cell == ".":
            score += 50
        else:
            score += 5  # propia celda

        # 🧠 espacio futuro (muy importante)
        space = bfs_space(current_board, (nx, ny), your_character)
        score += space * 2

        # 🛡️ distancia a enemigos
        if enemies:
            d = dist_to_nearest_enemy((nx, ny), enemies)
            score += d * 3

        # 🚶 movilidad local
        free_neighbors = 0
        for ddx, ddy in DIRS:
            tx, ty = nx + ddx, ny + ddy
            if inside(tx, ty) and not is_enemy(current_board[tx][ty], your_character):
                free_neighbors += 1

        score += free_neighbors * 10

        # ⚠️ penalizar encierros (pocos vecinos)
        if free_neighbors <= 1:
            score -= 100

        if score > best_score:
            best_score = score
            best_move = (nx, ny)

    return best_move