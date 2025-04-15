import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    subject_count = teacher.groupby('teacher_id')['subject_id'].nunique().reset_index()
    return subject_count.rename(columns={'subject_id': 'cnt'})
