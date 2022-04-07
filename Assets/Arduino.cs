using System.Collections;
using UnityEngine;
using System.IO.Ports;
using TMPro;
using UnityEngine.UI;

public class Arduino : MonoBehaviour
{
    SerialPort serialPort = new SerialPort("COM3", 9600);
    float roomTemp;
    int fanSpeed;
    int fanState = 0, lightState = 0;
    [SerializeField] TMP_Text temp;
    [SerializeField] TMP_Text speed;

    [SerializeField] Image fanButton;
    [SerializeField] Image lightButton;
    void Start()
    {
        serialPort.Open();
    }


    void Update()
    {
        if (serialPort.IsOpen)
        {
            string[] data = serialPort.ReadLine().Split();

            temp.text = data[0] + " C";
            speed.text = "x " + data[1];

            //serialPort.Write(fanState.ToString());
        }
    }

    public void ToggleFan()
    {
        if (fanState == 0)
        {
            fanState = 1;
            fanButton.color = Color.green;
        }
        else
        {
            fanState = 0;
            fanButton.color = Color.grey;
        }
    }

    public void ToggleLight()
    {
        if (lightState == 0)
        {
            lightState = 1;
            lightButton.color = Color.green;
        }
        else
        {
            lightState = 0;
            lightButton.color = Color.grey;
        }
    }
}
