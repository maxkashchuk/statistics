using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace additional_1
{
    public partial class Form1 : Form
    {
        Random rnd = new Random();

        List<int> X;

        double Yi;

        double matematychne_spodivanya;

        double seredniokvadratychne_vidhylennia;

        double kilkistN;

        List<int> generateX()
        {
            for (int i = 0; i < Int32.Parse(quntityValue.Text); i++)
            {
                X.Add(rnd.Next(Int32.Parse(aValue.Text), Int32.Parse(bValue.Text)));
            }
            for(int i = 0; i < X.Count; i++)
            {
                Console.WriteLine("Value " + i + " equals " + X[i] + '\n');
            }
            return X;
        }

        double Calculate(ref List<int> X)
        {
            double sum = 0;
            foreach(int i in X)
            {
                sum += i;
            }
            sum = sum - (kilkistN / 2);
            return matematychne_spodivanya + (seredniokvadratychne_vidhylennia / Math.Sqrt(kilkistN / 12)) * sum;
        }


        public Form1()
        {
            InitializeComponent();
            chart.Series.Clear();
            chart.Titles.Add("Formula values");
            chart.Series.Add("Values");
        }

        private void button_Click(object sender, EventArgs e)
        {
            double value;
            kilkistN = Double.Parse(kilkistZnachenN.Text);
            matematychne_spodivanya = Double.Parse(matematychneSpodivannyaField.Text);
            seredniokvadratychne_vidhylennia = Double.Parse(serednioKvadratychneVidhylenniaField.Text);
            X = new List<int>();
            X = generateX();
            value = Calculate(ref X);
            Console.WriteLine("\n\nResult is: " + value);
            chart.Series["Values"].Points.Add(value);
            chart.Update();
        }
    }
}
