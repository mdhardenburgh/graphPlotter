#ifndef GRAPH_PLOTTER_H
#define GRAPH_PLOTTER_H

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <tuple>

template <class T> class graphPlotter
{
    public:
        graphPlotter();
        graphPlotter(std::vector<T*> xData, std::vector<T*> yData);
        graphPlotter(std::vector<T*> xData, std::vector<T*> yData, std::vector<std::string> labels);
        //graphPlotter(std::vector<T*> xData, std::vector<T*> yData, std::vector<T*> zData); //coming soon
        //graphPlotter(std::vector<T*> xData, std::vector<T*> yData, std::vector<T*> yData, std::vector<std::string> labels); //coming soon
        ~graphPlotter();

        //if you want to change the graph without having to create a new one
        void setPlotData(std::vector<T*> xData, std::vector<T*> yData);
        void setPlotData(std::vector<T*> xData, std::vector<T*> yData, std::vector<std::string> labels);
        //void setPlotData(std::vector<T*> xData, std::vector<T*> yData, std::vector<T*> zData); //coming soon
        //void setPlotData(std::vector<T*> xData, std::vector<T*> yData, std::vector<T*> yData, std::vector<std::string> labels); //coming soon
        void setWindowSize(uint32_t xLength, uint32_t yLength);

        void setAxisLimits(T startX, T endX, T startY, T endY);
        void setAxisLabels(std::string xLabel, std::string yLabels);
        void showLegend(bool active);
        void showGrid(bool active);
        void showPlot(bool active);
        void setTitle(std::string plotTitle);
        static void setSuppressWarnings(bool active);

    private:
        //xData, yData
        std::tuple<std::vector<T*>, std::vector<T*>> m_graphData;
        std::vector<std::string> m_labels;
        std::string m_title = "hello world";
        static bool m_suppressWarnings = false;
        // xLength, yLength
        std::tuple<uint32_t, uint32_t> m_windowSize;
        // toX, fromX, toY, fromY
        std::tuple<T, T, T, T> axisLimits;
        // xLabel, yLabel
        std::tuple<std::string, std::string> m_axisLabels;
        bool m_showLegend = false;
        bool m_showGrid = false;
        bool m_showPlot = false;
};

template <class T> graphPlotter<T>::graphPlotter()
{
    // empty for now
}

template <class T> graphPlotter<T>::graphPlotter(std::vector<T*> xData, std::vector<T*> yData)
{
    if(xData.size() != yData.size())
    {
        std::cout<<__PRETTY_FUNCTION__<<": size of xData != size of yData"<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": size of xData is "<<xData.size()<<" size of yData is"<<yData.size()<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": aborting"<<std::endl;
        assert(false);
    }
    m_graphData = std::make_tuple(xData, yData);
}

template <class T> graphPlotter<T>::graphPlotter(std::vector<T*> xData, std::vector<T*> yData, std::vector<std::string> labels)
{
    if((xData.size() != yData.size()))
    {
        std::cout<<__PRETTY_FUNCTION__<<": size of xData != size of yData != size of labels"<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": size of xData is "<<xData.size()<<" size of yData is"<<yData.size()<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": aborting"<<std::endl;
        assert(false);
    }
    if((xData.size() != labels.size()) && (yData.size() != labels.size()) && !suppressWarnings)
    {
        std::cout<<__PRETTY_FUNCTION__<<": warning, the size of labels vector doesn't match xData or yData vector"<<std::endl;
    }
    
    m_graphData = std::make_tuple(xData, yData);
    m_labels = labels;
}

template <class T> graphPlotter<T>::~graphPlotter()
{
    // nothing here yet
}

template <class T> void graphPlotter<T>::setPlotData(std::vector<T*> xData, std::vector<T*> yData)
{
    if(xData.size() != yData.size())
    {
        std::cout<<__PRETTY_FUNCTION__<<": size of xData != size of yData"<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": size of xData is "<<xData.size()<<" size of yData is"<<yData.size()<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": aborting"<<std::endl;
        assert(false);
    }
    m_graphData = std::make_tuple(xData, yData);
}

template <class T> void graphPlotter<T>::setPlotData(std::vector<T*> xData, std::vector<T*> yData, std::vector<std::string> labels)
{
    if((xData.size() != yData.size()))
    {
        std::cout<<__PRETTY_FUNCTION__<<": size of xData != size of yData != size of labels"<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": size of xData is "<<xData.size()<<" size of yData is"<<yData.size()<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": aborting"<<std::endl;
        assert(false);
    }
    if((xData.size() != labels.size()) && (yData.size() != labels.size()) && !suppressWarnings)
    {
        std::cout<<__PRETTY_FUNCTION__<<": warning, the size of labels vector doesn't match xData or yData vector"<<std::endl;
    }
    
    m_graphData = std::make_tuple(xData, yData);
    m_labels = labels;
}

template <class T> void graphPlotter<T>::setWindowSize(uint32_t xLength, uint32_t yLength)
{
    m_windowSize = std::make_tuple(xLength, yLength);
}

template <class T> void graphPlotter<T>::setAxisLimits(T startX, T endX, T startY, T endY)
{
    if(startX > endX)
    {
        std::cout<<__PRETTY_FUNCTION__<<": start of the x limit is greater than end of the x limit"<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": start of the x limit is "<<startX<<", end of the x limit is"<endX<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": aborting"<<std::endl;
        assert(false);
    }
    if(startY > endY)
    {
        std::cout<<__PRETTY_FUNCTION__<<": start of the y limit is greater than end of the y limit"<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": start of the y limit is "<<startY<<", end of the y limit is"<endY<<std::endl;
        std::cout<<__PRETTY_FUNCTION__<<": aborting"<<std::endl;
        assert(false);
    }

    axisLimits = std::make_tuple(startX, endX, startY, endY);
}

#endif //GRAPH_PLOTTER_H