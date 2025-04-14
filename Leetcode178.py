import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    ranked_scores = scores.copy().drop('id', axis=1)
    ranked_scores.insert(1, 'rank', scores['score'].rank(method='dense', ascending=False))
    return ranked_scores.sort_values('score', ascending=False)
