void rotatePointV(int &x, int &y, int angle, int centerX, int centerY) {
  float radianAngle = angle * PI / 180.0;
  int tempX = x - centerX;
  int tempY = y - centerY;
  x = round(tempX * cos(radianAngle) - tempY * sin(radianAngle) + centerX);
  y = round(tempX * sin(radianAngle) + tempY * cos(radianAngle) + centerY);
}
void drawTriangleVolt1(int posX, int posY, int angle) {
  uint16_t triangleColor = tft.color565(0, 227, 91);

  int16_t x0 = 11;
  int16_t y0 = 16;
  int16_t x1 = 18;
  int16_t y1 = 9;
  int16_t x2 = 24;
  int16_t y2 = 16;

  int centerX = (x0 + x1 + x2) / 3;  // Calculate the center of the triangle
  int centerY = (y0 + y1 + y2) / 3;

  // Declare temporary variables for rotated coordinates
  int temp_x0 = x0;
  int temp_y0 = y0;
  int temp_x1 = x1;
  int temp_y1 = y1;
  int temp_x2 = x2;
  int temp_y2 = y2;

  // Rotate each point in place
  rotatePointV(temp_x0, temp_y0, angle, centerX, centerY);
  rotatePointV(temp_x1, temp_y1, angle, centerX, centerY);
  rotatePointV(temp_x2, temp_y2, angle, centerX, centerY);

  // Update original coordinates
  x0 = temp_x0;
  y0 = temp_y0;
  x1 = temp_x1;
  y1 = temp_y1;
  x2 = temp_x2;
  y2 = temp_y2;

  x0 += posX;
  y0 += posY;
  x1 += posX;
  y1 += posY;
  x2 += posX;
  y2 += posY;

  float scale = 1;
  x0 *= scale;
  y0 *= scale;
  x1 *= scale;
  y1 *= scale;
  x2 *= scale;
  y2 *= scale;

  tft.fillTriangle(x0, y0, x1, y1, x2, y2, triangleColor);
}
void drawTriangleVolt2(int posX, int posY, int angle) {
  uint16_t triangleColor = tft.color565(0, 227, 91);

  int16_t x0_2 = 11;
  int16_t y0_2 = 16;
  int16_t x1_2 = 18;
  int16_t y1_2 = 9;
  int16_t x2_2 = 24;
  int16_t y2_2 = 16;

  int centerX_2 = (x0_2 + x1_2 + x2_2) / 3;
  int centerY_2 = (y0_2 + y1_2 + y2_2) / 3;

  // Declare temporary variables for rotated coordinates
  int temp_x0_2 = x0_2;
  int temp_y0_2 = y0_2;
  int temp_x1_2 = x1_2;
  int temp_y1_2 = y1_2;
  int temp_x2_2 = x2_2;
  int temp_y2_2 = y2_2;

  // Rotate each point in place
  rotatePointV(temp_x0_2, temp_y0_2, angle, centerX_2, centerY_2);
  rotatePointV(temp_x1_2, temp_y1_2, angle, centerX_2, centerY_2);
  rotatePointV(temp_x2_2, temp_y2_2, angle, centerX_2, centerY_2);

  // Update original coordinates
  x0_2 = temp_x0_2;
  y0_2 = temp_y0_2;
  x1_2 = temp_x1_2;
  y1_2 = temp_y1_2;
  x2_2 = temp_x2_2;
  y2_2 = temp_y2_2;

  x0_2 += posX;
  y0_2 += posY;
  x1_2 += posX;
  y1_2 += posY;
  x2_2 += posX;
  y2_2 += posY;

  float scale = 1;
  x0_2 *= scale;
  y0_2 *= scale;
  x1_2 *= scale;
  y1_2 *= scale;
  x2_2 *= scale;
  y2_2 *= scale;

  tft.fillTriangle(x0_2, y0_2, x1_2, y1_2, x2_2, y2_2, triangleColor);
}
void drawTrianglePause(int posX, int posY, int angle) {
  uint16_t triangleColor = tft.color565(0, 227, 91);

  int16_t x0_3 = 11;
  int16_t y0_3 = 16;
  int16_t x1_3 = 18;
  int16_t y1_3 = 9;
  int16_t x2_3 = 24;
  int16_t y2_3 = 16;

  int centerX_3 = (x0_3 + x1_3 + x2_3) / 3;
  int centerY_3 = (y0_3 + y1_3 + y2_3) / 3;

  // Declare temporary variables for rotated coordinates
  int temp_x0_3 = x0_3;
  int temp_y0_3 = y0_3;
  int temp_x1_3 = x1_3;
  int temp_y1_3 = y1_3;
  int temp_x2_3 = x2_3;
  int temp_y2_3 = y2_3;

  // Rotate each point in place
  rotatePointV(temp_x0_3, temp_y0_3, angle, centerX_3, centerY_3);
  rotatePointV(temp_x1_3, temp_y1_3, angle, centerX_3, centerY_3);
  rotatePointV(temp_x2_3, temp_y2_3, angle, centerX_3, centerY_3);

  // Update original coordinates
  x0_3 = temp_x0_3;
  y0_3 = temp_y0_3;
  x1_3 = temp_x1_3;
  y1_3 = temp_y1_3;
  x2_3 = temp_x2_3;
  y2_3 = temp_y2_3;

  x0_3 += posX;
  y0_3 += posY;
  x1_3 += posX;
  y1_3 += posY;
  x2_3 += posX;
  y2_3 += posY;

  float scale = 1;
  x0_3 *= scale;
  y0_3 *= scale;
  x1_3 *= scale;
  y1_3 *= scale;
  x2_3 *= scale;
  y2_3 *= scale;

  tft.fillTriangle(x0_3, y0_3, x1_3, y1_3, x2_3, y2_3, triangleColor);
}
void drawGraphVolt1() {
  tft.setRotation(1);
  tft.drawFastHLine(13, 23, 294, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 24, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 40, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 56, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 72, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 88, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 104, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 120, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 136, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 152, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 168, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 184, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 200, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 215, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(13, 216, 294, tft.color565(13, 13, 13));//(вправо-влево,вверх-вниз,длина)
}
void drawGraphVolt2() {
  tft.setRotation(0);
  tft.drawFastHLine(23, 13, 193, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 14, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 30, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 46, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 62, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 78, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 94, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 110, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 126, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 142, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 158, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 174, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 190, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 206, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 222, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 238, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 255, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 271, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 288, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 305, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(23, 306, 193, tft.color565(13, 13, 13));
}
void drawTextGraph() {
  tft.setRotation(3);
  tft.loadFont(PTSans_Bold18);
  tft.setTextColor(tft.color565(255, 239, 0), tft.color565(0, 0, 0));
  tft.drawString("5.20V", 12, 4);
  tft.setTextColor(tft.color565(0, 227, 91), tft.color565(0, 0, 0));
  tft.drawString("0.10A", 262, 4);
  tft.setTextColor(tft.color565(255, 239, 0), tft.color565(0, 0, 0));
  tft.drawString("V", 137, 4);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(0, 0, 0));
  tft.drawString("/", 147, 2);
  tft.setTextColor(tft.color565(0, 227, 91), tft.color565(0, 0, 0));
  tft.drawString("A", 154, 4);
  tft.setTextColor(tft.color565(255, 239, 0), tft.color565(0, 0, 0));
  tft.drawString("5.00V", 12, 219);
  tft.setTextColor(tft.color565(0, 227, 91), tft.color565(0, 0, 0));
  tft.drawString("0.00A", 262, 219);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(0, 0, 0));
  tft.drawString("0.1s", 115, 219);
  tft.drawString("/", 150, 219);
  tft.drawString("div", 161, 219);
  tft.setRotation(0);
}
void drawPauseGraph() {
  static unsigned long buttonHoldTime1 = 0;
  static bool rectState1 = false;
  if (digitalRead(BUTTON_AVER) == LOW) {
    unsigned long currentMillis = millis();
    if (currentMillis - buttonHoldTime1 > 200) {
      if (!rectState1) {
        tft.setRotation(2);
        tft.fillRect(218, 108, 19, 19, tft.color565(0, 0, 0));
        tft.fillRect(220, 112, 15, 3, tft.color565(255, 0, 60));
        tft.fillRect(220, 120, 15, 3, tft.color565(255, 0, 60));
      } else {
        tft.setRotation(2);
        tft.fillRect(218, 108, 19, 19, tft.color565(0, 0, 0));
        drawTrianglePause(211, 106, 180);
        /*drawRotatedTriangle2(211, 98, 180);*/
      }
      rectState1 = !rectState1;
      buttonHoldTime1 = currentMillis;
    }
  } else {
    buttonHoldTime1 = 0;
  }
}
