import pandas as pd

def find_primary_department(employee: pd.DataFrame) -> pd.DataFrame:
    dept_counts = employee.groupby('employee_id')['department_id'].count().reset_index()
    single_departments = dept_counts[dept_counts['department_id'] == 1]
    return employee[(employee['employee_id'].isin(single_departments['employee_id'])) | (employee['primary_flag'] == 'Y')][['employee_id', 'department_id']]
