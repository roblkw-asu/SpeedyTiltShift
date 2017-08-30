package meteor.asu.edu.speedytiltshift;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    private Bitmap bmpIn;
    private Bitmap bmpOut;
    private ImageView imageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        BitmapFactory.Options opts = new BitmapFactory.Options();
        opts.inPreferredConfig = Bitmap.Config.ARGB_8888; // Each pixel is 4 bytes: Alpha, Red, Green, Blue
        bmpIn = BitmapFactory.decodeResource(getResources(), R.drawable.input, opts);
        imageView = (ImageView) findViewById(R.id.imageView);
    }
    public void tiltshiftjava(View view){
        bmpOut = SpeedyTiltShift.tiltshift_java(bmpIn, 100, 200, 300, 400, 0.5f, 2.1f);
        imageView.setImageBitmap(bmpOut);
    }
    public void tiltshiftcpp(View view){
        bmpOut = SpeedyTiltShift.tiltshift_cpp(bmpIn, 100, 200, 300, 400, 0.5f, 2.1f);
        imageView.setImageBitmap(bmpOut);
    }
    public void tiltshiftneon(View view){
        bmpOut = SpeedyTiltShift.tiltshift_neon(bmpIn, 100, 200, 300, 400, 0.5f, 2.1f);
        imageView.setImageBitmap(bmpOut);
    }
}

