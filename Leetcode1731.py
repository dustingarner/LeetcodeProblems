import pandas as pd

def count_employees(employees: pd.DataFrame) -> pd.DataFrame:
    manager_table = employees.merge(employees, left_on='employee_id', right_on='reports_to', suffixes=['', '_emp'])
    managers = manager_table.groupby(['employee_id', 'name'])[['employee_id_emp', 'age_emp']].agg(\
            {'employee_id_emp': 'count', 'age_emp': 'mean'}).reset_index()
    managers.rename(columns={'employee_id_emp': 'reports_count', 'age_emp': 'average_age'}, inplace=True)
    managers['average_age'] = (managers['average_age'] + 0.0000000000001).round()
    return managers
