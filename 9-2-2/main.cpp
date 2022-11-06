#include <iostream>
#include <vector>
#include "canvas.h"

using namespace std;

int main()
{
	size_t canvas_width, canvas_height;
	size_t x, y, width, height, dist;
	char brush;
	string cmd, shape;
	int i, n;

	vector<Shape*> shapes;

	cin >> canvas_width >> canvas_height;
	Canvas *canvas = new Canvas(canvas_width, canvas_height);
	canvas->Print();
	
	while (1) {
		cin >> cmd;
		if (cmd.compare("quit") == 0) break;
		if (cmd.compare("add") == 0) {
			cin >> shape;
			if (shape.compare("rect") == 0) {
				cin >> x >> y >> width >> height >> brush;
				Rectangle *rect = new Rectangle(x, y, width, height, brush);
				shapes.push_back(rect);
				rect->Draw(canvas);
			} else if (shape.compare("diamond") == 0) {
				cin >> x >> y >> dist >> brush;
				Diamond *diamond = new Diamond(x, y, dist, brush);
				shapes.push_back(diamond);
				diamond->Draw(canvas);
			} else if (shape.compare("tri_up") == 0) {
				cin >> x >> y >> height >> brush;
				UpTriangle *upTriangle = new UpTriangle(x, y, height, brush);
				shapes.push_back(upTriangle);
				upTriangle->Draw(canvas);
			} else if (shape.compare("tri_down") == 0) {
				cin >> x >> y >> height >> brush;
				DownTriangle *downTriangle = new DownTriangle(x, y, height, brush);
				shapes.push_back(downTriangle);
				downTriangle->Draw(canvas);
			}
		} else if (cmd.compare("delete") == 0) {
			cin >> n;
			if (n < shapes.size()) {
				shapes.erase(next(shapes.begin(), n));
				canvas->Clear();
				for (Shape *s : shapes)
					s->Draw(canvas);
			}
		} else if (cmd.compare("draw") == 0) {
			canvas->Print();
		} else if (cmd.compare("dump") == 0) {
			i = 0;
			for (Shape *s : shapes) {
				cout << i << ' ';
				s->GetInfo();
				i++;
			}
		} else if (cmd.compare("resize") == 0) {
			cin >> canvas_width >> canvas_height;
			canvas->Resize(canvas_width, canvas_height);
			for (Shape *s : shapes)
				s->Draw(canvas);
		}
	}

	delete canvas;
	return 0;
}
