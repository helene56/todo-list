from googleapiclient.discovery import build
# Range for data in sheet
RANGE_NAME = "A1:A3"

def get_values(spreadsheet_id, creds):
    service = build("sheets", "v4", credentials=creds)

    result = (
        service.spreadsheets()
        .values()
        .get(spreadsheetId=spreadsheet_id, range=RANGE_NAME)
        .execute()
    )
    data = result.get("values", [])
    # write the data from sheet to a txt doc
    output_for_data = "".join(sublist[0] for sublist in data)
    write_to_doc("text.txt", output_for_data)
    output = ", ".join(sublist[0] for sublist in data)
    print(output)

def write_to_doc(file, data):
    with open(file, 'w') as file:
        for value in data:
            file.write(f"{value}\n")