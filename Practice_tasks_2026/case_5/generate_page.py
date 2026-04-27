#!/usr/bin/env python3

ORGANIZATION_NAME = "Московский университет «Синергия»"
ORGANIZATION_FULL_NAME = "АНО ВО «Московский университет «Синергия»"

ORGANIZATION_INFO = {
    "Юридический адрес": "129090, г. Москва, ул. Мещанская, д. 9/14, стр. 1",
    "Организационно-правовая форма": "Автономная некоммерческая организация (АНО)",
    "ИНН": "9702078886",
    "ОГРН": "1257700508493",
    "Основная деятельность": "Образовательные услуги высшего и дополнительного профессионального образования",
    "Формат обучения": "Очный, заочный, дистанционный",
    "Официальный сайт": "https://synergy.ru",
}

FONTS = [
    {
        "name": "Montserrat",
        "label": "Официальный шрифт компании",
        "import": "https://fonts.googleapis.com/css2?family=Montserrat:wght@400;600;700&display=swap",
        "css": "'Montserrat', sans-serif",
        "badge": "official",
    },
    {
        "name": "Inter",
        "label": "Вариант 1",
        "import": "https://fonts.googleapis.com/css2?family=Inter:wght@400;600;700&display=swap",
        "css": "'Inter', sans-serif",
        "badge": "alt",
    },
    {
        "name": "Roboto",
        "label": "Вариант 2",
        "import": "https://fonts.googleapis.com/css2?family=Roboto:wght@400;500;700&display=swap",
        "css": "'Roboto', sans-serif",
        "badge": "alt",
    },
    {
        "name": "Open Sans",
        "label": "Вариант 3",
        "import": "https://fonts.googleapis.com/css2?family=Open+Sans:wght@400;600;700&display=swap",
        "css": "'Open Sans', sans-serif",
        "badge": "alt",
    },
    {
        "name": "Nunito",
        "label": "Вариант 4",
        "import": "https://fonts.googleapis.com/css2?family=Nunito:wght@400;600;700&display=swap",
        "css": "'Nunito', sans-serif",
        "badge": "alt",
    },
    {
        "name": "Raleway",
        "label": "Вариант 5",
        "import": "https://fonts.googleapis.com/css2?family=Raleway:wght@400;600;700&display=swap",
        "css": "'Raleway', sans-serif",
        "badge": "alt",
    },
]


def build_info_rows(info: dict) -> str:
    rows = []
    for key, value in info.items():
        cell = f'<a href="{value}" target="_blank">{value}</a>' if value.startswith("http") else value
        rows.append(
            f"""
            <tr>
                <td class="info-label">{key}</td>
                <td class="info-value">{cell}</td>
            </tr>"""
        )
    return "".join(rows)


def build_font_cards(fonts: list) -> str:
    cards = []
    for font in fonts:
        badge_class = "badge-official" if font["badge"] == "official" else "badge-alt"
        badge_text = "Официальный" if font["badge"] == "official" else "Альтернатива"
        cards.append(
            f"""
        <div class="font-card" style="font-family: {font['css']}">
            <div class="font-header">
                <span class="font-name">{font['name']}</span>
                <span class="badge {badge_class}">{badge_text}</span>
            </div>
            <p class="font-label">{font['label']}</p>
            <p class="font-sample">
                Московский университет «Синергия» — ведущий частный университет России.
                Образование для тех, кто хочет добиться результата.
            </p>
            <p class="font-meta">
                ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 0123456789
            </p>
        </div>"""
        )
    return "".join(cards)


def build_google_fonts_imports(fonts: list) -> str:
    return "\n    ".join(
        f'<link href="{font["import"]}" rel="stylesheet">'
        for font in fonts
    )


def generate_html(org_name: str, org_full_name: str, org_info: dict, fonts: list) -> str:
    font_imports = build_google_fonts_imports(fonts)
    info_rows = build_info_rows(org_info)
    font_cards = build_font_cards(fonts)
    official_css = fonts[0]["css"]

    return f"""<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>{org_name}</title>
    {font_imports}
    <style>
        * {{
            box-sizing: border-box;
        }}

        body {{
            margin: 0;
            font-family: {official_css};
            background: #f4f6fa;
            color: #1a1a2e;
            line-height: 1.6;
        }}

        header {{
            padding: 48px 24px;
            text-align: center;
            color: #fff;
            background: linear-gradient(135deg, #0a2463 0%, #1e4db7 100%);
        }}

        header h1 {{
            margin: 0 0 8px;
            font-size: 2.2rem;
        }}

        header p {{
            margin: 0;
            opacity: 0.9;
        }}

        main {{
            max-width: 960px;
            margin: 40px auto;
            padding: 0 20px;
        }}

        section {{
            margin-bottom: 24px;
            padding: 28px;
            border-radius: 12px;
            background: #fff;
            box-shadow: 0 2px 12px rgba(0, 0, 0, 0.07);
        }}

        h2 {{
            margin: 0 0 18px;
            color: #0a2463;
        }}

        table {{
            width: 100%;
            border-collapse: collapse;
        }}

        tr:not(:last-child) {{
            border-bottom: 1px solid #eef1f6;
        }}

        .info-label {{
            width: 38%;
            padding: 10px 16px 10px 0;
            font-weight: 600;
            color: #55607c;
            vertical-align: top;
        }}

        .info-value {{
            padding: 10px 0;
        }}

        .info-value a {{
            color: #1e4db7;
            text-decoration: none;
        }}

        .font-grid {{
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(280px, 1fr));
            gap: 18px;
        }}

        .font-card {{
            padding: 20px;
            border: 1px solid #e6ebf4;
            border-radius: 10px;
            background: #fafbff;
        }}

        .font-header {{
            display: flex;
            align-items: center;
            gap: 10px;
            margin-bottom: 6px;
        }}

        .font-name {{
            font-weight: 700;
            color: #0a2463;
        }}

        .badge {{
            padding: 2px 8px;
            border-radius: 999px;
            font-size: 0.7rem;
            font-weight: 700;
            text-transform: uppercase;
        }}

        .badge-official {{
            color: #1e4db7;
            background: #e8f0fe;
        }}

        .badge-alt {{
            color: #55607c;
            background: #eef1f6;
        }}

        .font-label {{
            margin: 0 0 10px;
            color: #7b859f;
            font-size: 0.9rem;
        }}

        .font-sample {{
            margin: 0 0 10px;
        }}

        .font-meta {{
            margin: 0;
            color: #9aa4be;
            font-size: 0.8rem;
        }}

        footer {{
            padding: 24px;
            text-align: center;
            color: #7b859f;
        }}
    </style>
</head>
<body>
    <header>
        <h1>{org_name}</h1>
        <p>{org_full_name}</p>
    </header>
    <main>
        <section>
            <h2>Об организации</h2>
            <table>
                {info_rows}
            </table>
        </section>
        <section>
            <h2>Варианты шрифтового оформления</h2>
            <div class="font-grid">
                {font_cards}
            </div>
        </section>
    </main>
    <footer>
        © 2026 {org_full_name}
    </footer>
</body>
</html>"""


def main() -> None:
    html_content = generate_html(
        org_name=ORGANIZATION_NAME,
        org_full_name=ORGANIZATION_FULL_NAME,
        org_info=ORGANIZATION_INFO,
        fonts=FONTS,
    )

    with open("index.html", "w", encoding="utf-8") as file:
        file.write(html_content)

    print("Файл index.html создан")


if __name__ == "__main__":
    main()
