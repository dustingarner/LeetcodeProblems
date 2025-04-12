import pandas as pd

def project_employees_i(project: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    df = project.merge(employee, on='employee_id')
    grouped = df[['project_id', 'experience_years']].groupby('project_id').mean()
    grouped.reset_index(inplace=True)
    grouped.rename(columns={'experience_years': 'average_years'}, inplace=True)
    grouped = grouped.round(2)
    return grouped
